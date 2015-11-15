#include <vector>
#include <string>
#include "profiles/Profile.h"
#include <langdetectpp/Language.h>
#include "profiles/Profile.h"
#include "profiles/ProfileGroup.h"
#include "util/CircleArray.h"
#include "util/misc.h"
#include "util/stats.h"
#include "ngrams/NGramExtractor.h"
#include "ngrams/ExtractedNGrams.h"
#include "detection/DetectionRunner.h"

using namespace std;
using langdetectpp::util::UniformIntDist;
using langdetectpp::util::Alpha;
using langdetectpp::profiles::ProfileGroup;

namespace langdetectpp { namespace detection {

const double CONV_THRESHOLD = 0.99999;
const size_t BASE_FREQ = 10000;
const size_t ITERATION_LIMIT = 1000;

DetectionRunner::DetectionRunner(shared_ptr<ProfileGroup> profGroup, ngrams::ExtractedNGrams &extracted)
  : profileGroup_(profGroup), textNGrams_(extracted){
    for (size_t i = 0; i < profileGroup_->profiles.size(); i++) {
      langScores_.push_back(0.0);
    }
  }

Language DetectionRunner::getBestScore() {
  double maxScore = 0.0;
  size_t maxIndex = 0;
  for (size_t i = 0; i < langScores_.size(); i++) {
    auto score = langScores_[i];
    if (score > maxScore) {
      maxScore = score;
      maxIndex = i;
    }
  }
  auto winningLang = profileGroup_->profiles.at(maxIndex);
  return winningLang->getLanguage();
}

Language DetectionRunner::detect() {
  const size_t numTrials = 7;
  for (size_t trialN = 0; trialN < numTrials; trialN++) {
    alpha_.warble();
    auto probs = runTrial();
    for (size_t j = 0; j < langScores_.size(); j++) {
      double divisor = (double) trialN;
      if (divisor <= 0) {
        divisor = 1.0;
      }
      double toAdd = (probs[j] / divisor);
      langScores_[j] += toAdd;
    }
  }
  return getBestScore();
}

std::vector<double>* DetectionRunner::getLanguageScoresForRandomNGramOrNull() {
  auto ngLen = ngramLengthDist_.get();
  vector<double> *langWordScores = nullptr;
  if (ngLen == 1) {
    auto ng = textNGrams_.randomOneGram();
    auto found = profileGroup_->oneGramWeights.find(ng);
    if (found != profileGroup_->oneGramWeights.end()) {
      langWordScores = &found->second;
    }
  } else if (ngLen == 2) {
    auto ng = textNGrams_.randomBigram();
    auto found = profileGroup_->bigramWeights.find(ng);
    if (found != profileGroup_->bigramWeights.end()) {
      langWordScores = &found->second;
    }
  } else if (ngLen == 3) {
    auto ng = textNGrams_.randomTrigram();
    auto found = profileGroup_->trigramWeights.find(ng);
    if (found != profileGroup_->trigramWeights.end()) {
      langWordScores = &found->second;
    }
  }
  return langWordScores;
}


std::vector<double> DetectionRunner::runTrial() {
  vector<double> probs;
  double startingProb = 1.0 / (double) profileGroup_->profiles.size();
  for (size_t i = 0; i < profileGroup_->profiles.size(); i++) {
    probs.push_back(startingProb);
  }
  for (size_t i = 0;; i++) {
    double weight = alpha_.get() / BASE_FREQ;
    auto langWordScores = getLanguageScoresForRandomNGramOrNull();
    if (langWordScores != nullptr) {
      for (size_t k = 0; k < langWordScores->size(); k++) {
        probs[k] *= (weight + langWordScores->at(k));
      }
    }

    if (i % 5 == 0) {
      double maxp = 0.0;
      double sump = 0.0;
      for (auto &elem: probs) {
        sump += elem;
      }
      for (size_t j = 0; j < probs.size(); j++) {
        double p = probs[j] / sump;
        if (maxp < p) {
          maxp = p;
        }
        probs[j] = p;
      }
      if (maxp > CONV_THRESHOLD || i >= ITERATION_LIMIT) {
        break;
      }
    }
  }
  return probs;
}

}} // langdetectpp::detection