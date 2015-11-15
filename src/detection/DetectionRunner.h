#pragma once
#include <vector>
#include <memory>
#include <tuple>
#include "profiles/Profile.h"
#include <langdetectpp/Language.h>
#include "util/stats.h"
#include "ngrams/ExtractedNGrams.h"

namespace langdetectpp { namespace detection {

class DetectionRunner {
 protected:
  std::shared_ptr<profiles::ProfileGroup> profileGroup_;
  ngrams::ExtractedNGrams &textNGrams_;
  std::vector<double> langScores_;
  util::UniformIntDist ngramLengthDist_ {1, 3};
  util::Alpha alpha_ {0.5, 0.05};
  std::vector<double> runTrial();
  Language getBestScore();
  std::vector<double>* getLanguageScoresForRandomNGramOrNull();
 public:
  DetectionRunner(
    std::shared_ptr<profiles::ProfileGroup>,
    ngrams::ExtractedNGrams&
  );
  Language detect();
};

}} // langdetectpp::detection