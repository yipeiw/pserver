#include "gtest/gtest.h"
#include "filter/fixing_float.h"

using namespace PS;
TEST(FIXING_FLOAT, BoolRand) {
  int n = 100000;
  SArray<float> res(n);
  int seed = time(NULL);
  for (int i = 0; i < n; ++i) {
    res[i] = FixingFloatFilter::randombool(&seed, 0.1);
  }
  LL << res.mean() << " " << res.std();
}

TEST(FIXING_FLOAT, EncodeDecode) {
  MessagePtr msg(new Message());
  auto conf = msg->addFilter(FilterConfig::FIXING_FLOAT)->mutable_fixed_point();
  conf->set_min_value(-90);
  conf->set_max_value(90);
  conf->set_num_bytes(3);

  SArray<float> ax = {100.0, .1, -100.0}; msg->addValue(ax);
  SArray<double> bx = {100.0, .1, -100.0}; msg->addValue(bx);


  FixingFloatFilter filter;
  filter.encode(msg);
  filter.decode(msg);

  LL << SArray<float>(msg->value[0]);
  LL << SArray<double>(msg->value[1]);
}

int main(int argc, char *argv[]) {
  FLAGS_logtostderr = 1;
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

