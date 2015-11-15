#pragma once

#include <string>
#include <queue>
#include <array>
#include <vector>
#include <tuple>

#include "utf8.h"
#include "util/CircleArray.h"
#include "util/stats.h"

namespace langdetectpp { namespace ngrams {

class ExtractedNGrams {
  std::vector<uint32_t> oneGrams_;
  std::vector<std::tuple<uint32_t, uint32_t>> bigrams_;
  std::vector<std::tuple<uint32_t, uint32_t, uint32_t>> trigrams_;
  util::UniformIntDist oneGramDist_;
  util::UniformIntDist bigramDist_;
  util::UniformIntDist trigramDist_;
 public:
  ExtractedNGrams(
    std::vector<uint32_t> ones,
    std::vector<std::tuple<uint32_t, uint32_t>> twos,
    std::vector<std::tuple<uint32_t, uint32_t, uint32_t>> threes
  ): oneGrams_(ones),
     bigrams_(twos),
     trigrams_(threes),
     oneGramDist_(0, oneGrams_.size() - 1),
     bigramDist_(0, bigrams_.size() - 1),
     trigramDist_(0, trigrams_.size() - 1) {}
  uint32_t randomOneGram() {
    return oneGrams_[oneGramDist_.get()];
  }
  std::tuple<uint32_t, uint32_t> randomBigram() {
    return bigrams_[bigramDist_.get()];
  }
  std::tuple<uint32_t, uint32_t, uint32_t> randomTrigram() {
    return trigrams_[trigramDist_.get()];
  }
};

}} // langdetectpp::ngrams
