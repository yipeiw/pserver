#pragma once
#include "filter/wiehgt_sensitive_sample.h"
#include "filter/filter.h"
#include "linear_method/linear_method.pb.h"
#include "math.h"

namespace PS{

class SampleFilter{
 public:
  template <typename V> 
  void encode(SArray<V>& value) {
          int K = std::floor(expect_percent_*value.size());
          WeightSensitiveSample(value, K);
          sampleThresholdCut(value, leftIdx, rightIdx, expected_num_);
  }

  void setPercent(float p) {expect_percent_ = p; }
  double getPercent() { return expect_percent_; }

 private:
  int expected_num_;
  bool setNumTag=false;
  float expect_percent_;
  bool setPercentTag = false;
  double threshold_ = 0.0;
};

}
