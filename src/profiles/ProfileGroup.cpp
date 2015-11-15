#include <vector>
#include <tuple>
#include <memory>
#include <unordered_map>
#include <folly/Hash.h>
#include "profiles/Profile.h"
#include "profiles/ProfileGroup.h"

using namespace std;

namespace langdetectpp { namespace profiles {

shared_ptr<ProfileGroup> ProfileGroup::create() {
  shared_ptr<ProfileGroup> result(new ProfileGroup);
  result->profiles.push_back(Profile::loadEnglish());
  result->profiles.push_back(Profile::loadRussian());
  result->profiles.push_back(Profile::loadSpanish());
  result->profiles.push_back(Profile::loadGerman());
  result->profiles.push_back(Profile::loadItalian());
  result->profiles.push_back(Profile::loadFrench());
  result->profiles.push_back(Profile::loadArabic());

  size_t profileCount = result->profiles.size();
  for (size_t i = 0; i < profileCount; i++) {
    auto currentProfile = result->profiles.at(i);

    // index 1-grams
    for (auto &elem: currentProfile->oneGrams_) {
      auto found = result->oneGramWeights.find(elem.first);
      double elemScore = ((double) elem.second) / ((double) std::get<0>(currentProfile->nWords_));
      if (found == result->oneGramWeights.end()) {
        vector<double> langRow;
        for (size_t j = 0; j < profileCount; j++) {
          langRow.push_back(0.0);
        }
        langRow[i] = elemScore;
        result->oneGramWeights.insert(std::make_pair(elem.first, langRow));
      } else {
        found->second[i] = elemScore;
      }
    }

    // index bigrams
    for (auto &elem: currentProfile->bigrams_) {
      auto found = result->bigramWeights.find(elem.first);
      double elemScore = ((double) elem.second) / ((double) std::get<1>(currentProfile->nWords_));
      if (found == result->bigramWeights.end()) {
        vector<double> langRow;
        for (size_t j = 0; j < profileCount; j++) {
          langRow.push_back(0.0);
        }
        langRow[i] = elemScore;
        result->bigramWeights.insert(std::make_pair(elem.first, langRow));
      } else {
        found->second[i] = elemScore;
      }
    }

    // index trigrams
    for (auto &elem: currentProfile->trigrams_) {
      auto found = result->trigramWeights.find(elem.first);
      double elemScore = ((double) elem.second) / ((double) std::get<2>(currentProfile->nWords_));
      if (found == result->trigramWeights.end()) {
        vector<double> langRow;
        for (size_t j = 0; j < profileCount; j++) {
          langRow.push_back(0.0);
        }
        langRow[i] = elemScore;
        result->trigramWeights.insert(std::make_pair(elem.first, langRow));
      } else {
        found->second[i] = elemScore;
      }
    }
  }
  return result;
}

}} // langdetectpp::profiles