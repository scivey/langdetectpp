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
  result->profiles.push_back(Profile::loadAf());
  result->profiles.push_back(Profile::loadAr());
  result->profiles.push_back(Profile::loadBg());
  result->profiles.push_back(Profile::loadBn());
  result->profiles.push_back(Profile::loadCa());
  result->profiles.push_back(Profile::loadCs());
  result->profiles.push_back(Profile::loadCy());
  result->profiles.push_back(Profile::loadDa());
  result->profiles.push_back(Profile::loadDe());
  result->profiles.push_back(Profile::loadEl());
  result->profiles.push_back(Profile::loadEn());
  result->profiles.push_back(Profile::loadEs());
  result->profiles.push_back(Profile::loadEt());
  result->profiles.push_back(Profile::loadFa());
  result->profiles.push_back(Profile::loadFi());
  result->profiles.push_back(Profile::loadFr());
  result->profiles.push_back(Profile::loadGu());
  result->profiles.push_back(Profile::loadHe());
  result->profiles.push_back(Profile::loadHi());
  result->profiles.push_back(Profile::loadHr());
  result->profiles.push_back(Profile::loadHu());
  result->profiles.push_back(Profile::loadId());
  result->profiles.push_back(Profile::loadIt());
  result->profiles.push_back(Profile::loadJa());
  result->profiles.push_back(Profile::loadKn());
  result->profiles.push_back(Profile::loadKo());
  result->profiles.push_back(Profile::loadLt());
  result->profiles.push_back(Profile::loadLv());
  result->profiles.push_back(Profile::loadMk());
  result->profiles.push_back(Profile::loadMl());
  result->profiles.push_back(Profile::loadMr());
  result->profiles.push_back(Profile::loadNe());
  result->profiles.push_back(Profile::loadNl());
  result->profiles.push_back(Profile::loadNo());
  result->profiles.push_back(Profile::loadPa());
  result->profiles.push_back(Profile::loadPl());
  result->profiles.push_back(Profile::loadPt());
  result->profiles.push_back(Profile::loadRo());
  result->profiles.push_back(Profile::loadRu());
  result->profiles.push_back(Profile::loadSk());
  result->profiles.push_back(Profile::loadSl());
  result->profiles.push_back(Profile::loadSo());
  result->profiles.push_back(Profile::loadSq());
  result->profiles.push_back(Profile::loadSv());
  result->profiles.push_back(Profile::loadSw());
  result->profiles.push_back(Profile::loadTa());
  result->profiles.push_back(Profile::loadTe());
  result->profiles.push_back(Profile::loadTh());
  result->profiles.push_back(Profile::loadTl());
  result->profiles.push_back(Profile::loadTr());
  result->profiles.push_back(Profile::loadUk());
  result->profiles.push_back(Profile::loadUr());
  result->profiles.push_back(Profile::loadVi());
  result->profiles.push_back(Profile::loadZhCn());
  result->profiles.push_back(Profile::loadZhTw());


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