#pragma once
#include <random>

namespace langdetectpp { namespace util {

class NormalDist {
 protected:
  std::default_random_engine generator_;
  std::normal_distribution<double> distribution_;
 public:
  NormalDist(double mean, double stdev): distribution_(mean, stdev){}
  double get() {
    return distribution_(generator_);
  }
};

class UniformIntDist {
 protected:
  std::default_random_engine generator_;
  std::uniform_int_distribution<size_t> distribution_;
 public:
  UniformIntDist(size_t start, size_t end): distribution_(start, end){}
  size_t get() {
    return distribution_(generator_);
  }
};

class Alpha {
 protected:
  double alpha_;
  double alphaWidth_;
  NormalDist distribution_;
 public:
  Alpha(double alpha, double alphaWidth)
    : alpha_(alpha), alphaWidth_(alphaWidth), distribution_(0.0, 1.0) {}
  double get() const {
    return alpha_;
  }
  void warble() {
    alpha_ = alpha_ + (distribution_.get() * alphaWidth_);
  }
};

}} // langdetectpp::util