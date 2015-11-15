#pragma once
#include <string>
#include <queue>
#include <array>
#include <vector>
#include <tuple>

#include "utf8.h"
#include "util/CircleArray.h"
#include "ngrams/ExtractedNGrams.h"

namespace langdetectpp { namespace ngrams {

class NGramExtractor {
 protected:
  char *iter_ {nullptr};
  char *end_ {nullptr};
  const std::string &textRef_;
  util::CircleArray<uint32_t, 3> codePoints_;
  std::vector<uint32_t> oneGrams_;
  std::vector<std::tuple<uint32_t, uint32_t>> bigrams_;
  std::vector<std::tuple<uint32_t, uint32_t, uint32_t>> trigrams_;
  bool advance();
 public:
  NGramExtractor(const std::string &text);
  bool good();
  ExtractedNGrams extract();
};

}} // langdetectpp::ngrams
