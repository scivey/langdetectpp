#pragma once
#include <vector>
#include <tuple>
#include <memory>
#include <unordered_map>
#include <folly/Hash.h>
#include "profiles/Profile.h"

namespace langdetectpp { namespace profiles {

class ProfileGroup {
 protected:
  ProfileGroup(){}
 public:
  std::vector<std::shared_ptr<Profile>> profiles;
  std::unordered_map<uint32_t, std::vector<double>> oneGramWeights;
  std::unordered_map<std::tuple<uint32_t, uint32_t>, std::vector<double>> bigramWeights;
  std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, std::vector<double>> trigramWeights;

  static std::shared_ptr<ProfileGroup> create();
};

}} // langdetectpp::profiles