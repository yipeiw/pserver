#pragma once
#include "util/split.h"
#include "learner/bcd.h"
#include "util/bitmap.h"
#include "filter/sparse_filter.h"
#include "app/linear_method/linear.h"

namespace PS {
namespace LM {
typedef double Real;

class DarlinCommon {
 public:
  DarlinCommon() { }
  ~DarlinCommon() { }
  Real newDelta(Real delta_max, Real delta_w) {
    return std::min(delta_max, 2 * fabs(delta_w) + .1);
  }
 protected:
  std::unordered_map<int, Bitmap> active_set_;
  std::unordered_map<int, SArray<Real>> delta_;
  SparseFilter kkt_filter_;
  Real kkt_filter_threshold_;
};

class DarlinScheduler : public BCDScheduler, DarlinCommon, LinearMethod {
 public:
  DarlinScheduler(const string& name, const Config& conf)
      : BCDScheduler(name, conf.darlin()), LinearMethod(conf) { }
  virtual ~DarlinScheduler() { }

  virtual void run() {
    CHECK_EQ(conf_.loss().type(), LossConfig::LOGIT);
    CHECK_EQ(conf_.penalty().type(), PenaltyConfig::L1);
    LI << "Train l_1 logistic regression by block coordinate descent";

    loadTrainingData(conf_.training_data());

    divideFeatureBlocks();

    auto darlin = conf_.darlin();
    int tau = darlin.max_block_delay();
    LI << "Maximal allowed delay: " << tau;
    bool random_blk_order = darlin.random_feature_block_order();
    if (!random_blk_order) {
      LI << "Warning: Randomized block order often acclerates the convergence.";
    }
    kkt_filter_threshold_ = 1e20;
    bool reset_kkt_filter = false;


    // iterating
    int max_iter = darlin.max_pass_of_data();
    auto pool = port(kCompGroup);
    // pick up a large enough time stamp to avoid any possible conflict
    int time = std::max(10000, pool->time() + (int)fea_grp_.size() * time_ratio_);
    const int first_time = time + 1;
    for (int iter = 0; iter < max_iter; ++iter) {
      // pick up an updating order
      auto order = blk_order_;
      if (random_blk_order) std::random_shuffle(order.begin(), order.end());
      if (iter == 0) order.insert(
              order.begin(), prior_blk_order_.begin(), prior_blk_order_.end());

      // iterating on feature blocks
      for (int i = 0; i < order.size(); ++i) {
        Task update;
        auto cmd = update.mutable_bcd();
        cmd->set_cmd(BCDCall::UPDATE_MODEL);
        // kkt filter
        if (i == 0) {
          cmd->set_kkt_filter_threshold(kkt_filter_threshold_);
          if (reset_kkt_filter) cmd->set_reset_kkt_filter(true);
        }
        // block info
        auto blk = fea_blk_[order[i]];
        blk.second.to(cmd->mutable_key());
        cmd->add_fea_grp(blk.first);

        // time stamp
        update.set_time(time+1);
        int wait_time = time - tau;
        // force zero delay for important feature blocks
        if (iter == 0 && i < prior_blk_order_.size()) {
          wait_time = time;
        }
        // make sure leading UPDATE_MODEL tasks could be picked up by workers
        if (wait_time < first_time) {
          wait_time = Message::kInvalidTime;
        }
        update.add_wait_time(wait_time);

        time = pool->submit(update);
      }

      // evaluate the progress
      Task eval;  eval.mutable_bcd()->set_cmd(BCDCall::EVALUATE_PROGRESS);
      if (time - tau >= first_time) {
        eval.add_wait_time(time - tau);
      }
      time = pool->submitAndWait(
          eval, [this, iter](){ mergeProgress(iter); });
      showProgress(iter);

      // update the kkt filter strategy
      Real vio = g_progress_[iter].violation();
      Real ratio = bcd_conf_.GetExtension(kkt_filter_threshold_ratio);

      kkt_filter_threshold_ = vio / (Real)g_train_info_.num_ex() * ratio;

      // check if finished
      Real rel = g_progress_[iter].relative_obj();
      if (rel > 0 && rel <= darlin.epsilon()) {
        if (reset_kkt_filter) {
          LI << "Stopped: relative objective <= " << darlin.epsilon();
          break;
        } else {
          reset_kkt_filter = true;
        }
      } else {
        reset_kkt_filter = false;
      }
      if (iter == max_iter - 1) {
        LI << "Reached maximal " << max_iter << " data passes";
      }
    }

    // save model
    if (conf_.has_model_output()) {
      saveModel(conf_.model_output());
    }
  }
 protected:
  // TOOD merge

  void showKKTFilter(int iter) {
    if (iter == -3) {
      fprintf(stderr, "|      KKT filter     ");
    } else if (iter == -2) {
      fprintf(stderr, "| threshold  #activet ");
    } else if (iter == -1) {
      fprintf(stderr, "+---------------------");
    } else {
      fprintf(stderr, "| %.1e %11llu ",
              kkt_filter_threshold_, (uint64)g_progress_[iter].nnz_active_set());
    }
  }

  void showProgress(int iter) {
    int s = iter == 0 ? -3 : iter;
    for (int i = s; i <= iter; ++i) {
      showObjective(i);
      showKKTFilter(i);
      showTime(i);
    }
  }

};

class DarlinServer : public BCDServer<Real>, DarlinCommon, LinearMethod {
 public:
  DarlinServer(const string& name, const Config& conf)
                  : BCDServer<Real>(name, conf.darlin()), LinearMethod(conf) { }
  virtual ~DarlinServer() { }

 protected:
  virtual void preprocessData(int time, const BCDCall& call) {
    BCDServer<Real>::preprocessData(time, call);
    for (int grp : fea_grp_) {
      size_t n = model_.key(grp).size();
      active_set_[grp].resize(n, true);
      delta_[grp].resize(n, bcd_conf_.GetExtension(delta_init_value));
    }
  }
  virtual void updateModel(int time, const BCDCall& call) {
    if (call.has_kkt_filter_threshold()) {
      kkt_filter_threshold_ = call.kkt_filter_threshold();
      violation_ = 0;
    }
    if (call.reset_kkt_filter()) {
      for (int grp : fea_grp_) active_set_[grp].fill(true);
    }
    CHECK_EQ(call.fea_grp_size(), 1);
    int grp = call.fea_grp(0);
    Range<Key> g_key_range(call.key());
    auto col_range = model_.find(grp, g_key_range);

    // none of my bussiness
    if (model_.myKeyRange().setIntersection(g_key_range).empty()) return;

    //  aggregate all workers' local gradients
    model_.waitInMsg(kWorkerGroup, time);

    // update the weights
    if (!col_range.empty()) {
      auto data = model_.received(time);
      CHECK_EQ(col_range, data.first);
      CHECK_EQ(data.second.size(), 2);

      updateWeight(grp, col_range, data.second[0], data.second[1]);
    }

    model_.finish(kWorkerGroup, time+1);
  }

  void updateWeight(int grp, SizeR range, SArray<Real> G, SArray<Real> U) {
    CHECK_EQ(G.size(), range.size());
    CHECK_EQ(U.size(), range.size());

    Real eta = conf_.learning_rate().alpha();
    Real lambda = conf_.penalty().lambda(0);
    Real delta_max = bcd_conf_.GetExtension(delta_max_value);
    auto& value = model_.value(grp);
    auto& active_set = active_set_[grp];
    auto& delta = delta_[grp];
    for (size_t i = 0; i < range.size(); ++i) {
      size_t k = i + range.begin();
      if (!active_set.test(k)) continue;
      Real g = G[i], u = U[i] / eta + 1e-10;
      Real g_pos = g + lambda, g_neg = g - lambda;
      Real& w = value[k];
      Real d = - w, vio = 0;

      if (w == 0) {
        if (g_pos < 0) {
          vio = - g_pos;
        } else if (g_neg > 0) {
          vio = g_neg;
        } else if (g_pos > kkt_filter_threshold_ && g_neg < - kkt_filter_threshold_) {
          active_set.clear(k);
          kkt_filter_.mark(&w);
          continue;
        }
      }
      violation_ = std::max(violation_, vio);

      if (g_pos <= u * w) {
        d = - g_pos / u;
      } else if (g_neg >= u * w) {
        d = - g_neg / u;
      }
      d = std::min(delta[k], std::max(-delta[k], d));
      delta[k] = newDelta(delta_max, d);
      w += d;
    }
  }

  virtual void evaluate(BCDProgress* prog) {
    size_t nnz_w = 0;
    size_t nnz_as = 0;
    Real objv = 0;
    for (int grp : fea_grp_) {
      const auto& value = model_.value(grp);
      for (Real w : value) {
        if (kkt_filter_.marked(w) || w == 0) continue;
        ++ nnz_w;
        objv += fabs(w);
      }
      nnz_as += active_set_[grp].nnz();
    }
    prog->set_objective(objv * conf_.penalty().lambda(0));
    prog->set_nnz_w(nnz_w);
    prog->set_violation(violation_);
    prog->set_nnz_active_set(nnz_as);
  }

  Real kkt_filter_threshold_ = 1e20;
  Real violation_ = 0;

  std::unordered_map<int, Bitmap> active_set_;
  std::unordered_map<int, SArray<Real>> delta_;
  SparseFilter kkt_filter_;
};

class DarlinWorker : public BCDWorker<Real>, DarlinCommon, LinearMethod {
 public:
  DarlinWorker(const string& name, const Config& conf)
      : BCDWorker<Real>(name, conf.darlin()), LinearMethod(conf) { }
  virtual ~DarlinWorker() { }
 protected:

  virtual void preprocessData(int time, const BCDCall& call) {
    BCDWorker<Real>::preprocessData(time, call);
    // dual_ = exp(y.*(X_*w_))
    if (bcd_conf_.init_w().type() == ParameterInitConfig::ZERO) {
      dual_.setValue(1);  // an optimizatoin
    } else {
      dual_.eigenArray() = exp(y_->value().eigenArray() * dual_.eigenArray());
    }
    for (int grp : fea_grp_) {
      size_t n = model_.key(grp).size();
      active_set_[grp].resize(n, true);
      delta_[grp].resize(n, bcd_conf_.GetExtension(delta_init_value));
    }
  }

  virtual void computeGradient(int time, const BCDCall& call, MessagePtr msg) {
    if (call.reset_kkt_filter()) {
      for (int grp : fea_grp_) active_set_[grp].fill(true);
    }
    CHECK_EQ(call.fea_grp_size(), 1);
    int grp = call.fea_grp(0);
    Range<Key> g_key_range(call.key());
    auto col_range = model_.find(grp, g_key_range);

    // compute and push the gradient
    computeAndPushGradient(time, g_key_range, grp, col_range);

    // pull the updated model, and update dual
    pullAndUpdateDual(time+2, g_key_range, grp, col_range, msg);

    // this task is not finished until the updated model is pulled
    msg->finished = false;
  }


  void pullAndUpdateDual(
      int time, Range<Key> g_key_range, int grp, SizeR col_range,
      const MessagePtr& msg) {
    // pull the updated weight from the server
    MessagePtr pull(new Message(kServerGroup, time, time-1));
    pull->setKey(model_.key(grp).segment(col_range));
    g_key_range.to(pull->task.mutable_key_range());
    pull->task.set_key_channel(grp);
    pull->addFilter(FilterConfig::KEY_CACHING);

    // once data pulled successfully, update dual_
    pull->fin_handle = [this, time, grp, col_range, msg](){
      if (!col_range.empty()) {
        auto data = model_.received(time);
        CHECK_EQ(col_range, data.first);
        CHECK_EQ(data.second.size(), 1);
        updateDual(grp, col_range, data.second[0]);
      }

      // mark the message finished, and reply the sender
      port(msg->sender)->finishIncomingTask(msg->task.time());
      sys_.reply(msg->sender, msg->task);
    };

    CHECK_EQ(time, model_.pull(pull));
  }

  void computeAndPushGradient(
      int time, Range<Key> g_key_range, int grp, SizeR col_range) {
    SArray<Real> G(col_range.size(), 0);
    SArray<Real> U(col_range.size(), 0);

    mu_.lock();  // lock the dual_
    busy_timer_.start();
    // compute the gradient in multi-thread
    if (!col_range.empty()) {
      CHECK_GT(FLAGS_num_threads, 0);
      // TODO partition by rows for small col_range size
      int num_threads = col_range.size() < 64 ? 1 : FLAGS_num_threads;
      ThreadPool pool(num_threads);
      int npart = num_threads * 1;  // could use a larger partition number
      for (int i = 0; i < npart; ++i) {
        auto thr_range = col_range.evenDivide(npart, i);
        if (thr_range.empty()) continue;
        auto gr = thr_range - col_range.begin();
        pool.add([this, grp, thr_range, gr, &G, &U]() {
            computeGradient(grp, thr_range, G.segment(gr), U.segment(gr));
          });
      }
      pool.startWorkers();
    }
    busy_timer_.stop();
    mu_.unlock();  // lock the dual_

    // push the gradient into servers
    MessagePtr push(new Message(kServerGroup, time));
    push->setKey(model_.key(grp).segment(col_range));
    push->addValue({G, U});
    g_key_range.to(push->task.mutable_key_range());
    push->task.set_key_channel(grp);
    push->addFilter(FilterConfig::KEY_CACHING);
    CHECK_EQ(time, model_.push(push));
  }

  void computeGradient(
      int grp, SizeR col_range, SArray<Real> G, SArray<Real> U) {
    CHECK_EQ(G.size(), col_range.size());
    CHECK_EQ(U.size(), col_range.size());
    CHECK(X_[grp]->colMajor());

    const auto& active_set = active_set_[grp];
    const auto& delta = delta_[grp];
    const Real* y = y_->value().data();
    auto X = std::static_pointer_cast<SparseMatrix<uint32, Real>>(
        X_[grp]->colBlock(col_range));
    const size_t* offset = X->offset().data();
    uint32* index = X->index().data() + offset[0];
    Real* value = X->value().data() + offset[0];
    bool binary = X->binary();

    // j: column id, i: row id
    for (size_t j = 0; j < X->cols(); ++j) {
      size_t k = j + col_range.begin();
      size_t n = offset[j+1] - offset[j];
      if (!active_set.test(k)) {
        index += n;
        if (!binary) value += n;
        kkt_filter_.mark(&G[j]);
        kkt_filter_.mark(&U[j]);
        continue;
      }
      Real g = 0, u = 0;
      Real d = binary ? exp(delta[k]) : delta[k];
      // TODO unroll loop
      for (size_t o = 0; o < n; ++o) {
        auto i = *(index ++);
        Real tau = 1 / ( 1 + dual_[i] );
        if (binary) {
          g -= y[i] * tau;
          u += std::min(tau*(1-tau)*d, .25);
          // u += tau * (1-tau);
        } else {
          Real v = *(value++);
          g -= y[i] * tau * v;
          u += std::min(tau*(1-tau)*exp(fabs(v)*d), .25) * v * v;
          // u += tau * (1-tau) * v * v;
        }
      }
      G[j] = g; U[j] = u;
    }
  }

  void updateDual(int grp, SizeR col_range, SArray<Real> new_w) {
    auto& cur_w = model_.value(grp);
    auto& active_set = active_set_[grp];
    auto& delta = delta_[grp];

    Real delta_max = bcd_conf_.GetExtension(delta_max_value);
    SArray<Real> delta_w(new_w.size());
    for (size_t i = 0; i < new_w.size(); ++i) {
      size_t j = col_range.begin() + i;
      Real& cw = cur_w[j];
      Real& nw = new_w[i];
      if (kkt_filter_.marked(nw)) {
        active_set.clear(j);
        cw = 0;
        delta_w[i] = 0;
        continue;
      }
      delta_w[i] = nw - cw;
      delta[j] = newDelta(delta_max, delta_w[i]);
      cw = nw;
    }

    CHECK(X_[grp]);

    mu_.lock();  // lock the dual_
    busy_timer_.start();
    {
      SizeR row_range(0, X_[grp]->rows());
      ThreadPool pool(FLAGS_num_threads);
      int npart = FLAGS_num_threads;
      for (int i = 0; i < npart; ++i) {
        auto thr_range = row_range.evenDivide(npart, i);
        if (thr_range.empty()) continue;
        pool.add([this, grp, thr_range, col_range, delta_w]() {
            updateDual(grp, thr_range, col_range, delta_w);
          });
      }
      pool.startWorkers();
    }
    busy_timer_.stop();
    mu_.unlock();  // lock the dual_
  }

  void updateDual(
      int grp, SizeR row_range, SizeR col_range, SArray<Real> w_delta) {
    CHECK_EQ(w_delta.size(), col_range.size());
    CHECK(X_[grp]->colMajor());

    const auto& active_set = active_set_[grp];
    Real* y = y_->value().data();
    auto X = std::static_pointer_cast<
      SparseMatrix<uint32, Real>>(X_[grp]->colBlock(col_range));
    size_t* offset = X->offset().data();
    uint32* index = X->index().data() + offset[0];
    Real* value = X->value().data();
    bool binary = X->binary();

    // j: column id, i: row id
    for (size_t j = 0; j < X->cols(); ++j) {
      size_t k  = j + col_range.begin();
      size_t n = offset[j+1] - offset[j];
      Real wd = w_delta[j];
      if (wd == 0 || !active_set.test(k)) {
        index += n;
        continue;
      }
      // TODO unroll the loop
      for (size_t o = offset[j]; o < offset[j+1]; ++o) {
        auto i = *(index++);
        if (!row_range.contains(i)) continue;
        dual_[i] *= binary ? exp(y[i] * wd) : exp(y[i] * wd * value[o]);
      }
    }
  }

  void evaluate(BCDProgress* prog) {
    busy_timer_.start();
    mu_.lock();  // lock the dual_
    prog->set_objective(log(1+1/dual_.eigenArray()).sum());
    mu_.unlock();
    prog->add_busy_time(busy_timer_.stop());
    busy_timer_.restart();
  };
 protected:
  Timer busy_timer_;
};

} // namespace LM
} // namespace PS
