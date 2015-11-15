#pragma once
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <folly/Conv.h>

namespace langdetectpp { namespace util {

template<typename T1, typename T2>
std::string tupleString(const std::tuple<T1, T2> &aTuple) {
  std::ostringstream oss;
  oss << "tuple<>("
      << folly::to<std::string>(std::get<0>(aTuple))
      << ", "
      << folly::to<std::string>(std::get<1>(aTuple))
      << ")";
  return oss.str();
}

template<typename T1, typename T2, typename T3>
std::string tupleString(const std::tuple<T1, T2, T3> &aTuple) {
  std::ostringstream oss;
  oss << "tuple<>("
      << folly::to<std::string>(std::get<0>(aTuple))
      << ", "
      << folly::to<std::string>(std::get<1>(aTuple))
      << ", "
      << folly::to<std::string>(std::get<2>(aTuple))
      << ")";
  return oss.str();
}

template<typename T>
std::unordered_map<T, size_t> countVec(const std::vector<T> &elems) {
  std::unordered_map<T, size_t> result;
  for (auto &elem: elems) {
    auto found = result.find(elem);
    if (found == result.end()) {
      result.insert(make_pair(elem, 1));
    } else {
      found->second++;
    }
  }
  return result;
}


}} // langdetectpp::util