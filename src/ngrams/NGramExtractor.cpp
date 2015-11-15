#include <string>
#include <queue>
#include <array>
#include <vector>
#include <tuple>

#include "utf8.h"
#include "util/CircleArray.h"
#include "ngrams/ExtractedNGrams.h"
#include "ngrams/NGramExtractor.h"

namespace langdetectpp { namespace ngrams {

NGramExtractor::NGramExtractor(const std::string &text): textRef_(text){
  iter_ = (char*) textRef_.c_str();
  uintptr_t endPtr = (uintptr_t) iter_;
  endPtr += textRef_.size();
  end_ = (char*) endPtr;
}

bool NGramExtractor::good() {
  return (iter_ != end_);
}

bool NGramExtractor::advance() {
  if (!good()) {
    return false;
  }
  uint32_t cPoint = utf8::next(iter_, end_);
  codePoints_.push(cPoint);
  return true;
}

ExtractedNGrams NGramExtractor::extract() {
  for (size_t i = 0; i < 3; i++) {
    if (!advance()) {
      return ExtractedNGrams(
        std::move(oneGrams_),
        std::move(bigrams_),
        std::move(trigrams_)
      );
    }
  }
  oneGrams_.push_back(codePoints_.getOne());
  bigrams_.push_back(codePoints_.getTwo());
  trigrams_.push_back(codePoints_.getThree());
  while (advance()) {
    oneGrams_.push_back(codePoints_.getOne());
    bigrams_.push_back(codePoints_.getTwo());
    trigrams_.push_back(codePoints_.getThree());
  }
  return ExtractedNGrams(
    std::move(oneGrams_),
    std::move(bigrams_),
    std::move(trigrams_)
  );
}

}} // langdetectpp::ngrams