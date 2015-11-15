#pragma once
#include <unordered_map>
#include <tuple>
#include <folly/Hash.h>

namespace profiles {

std::unordered_map<uint32_t, size_t> get_et_one_grams();

std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_et_bigrams();

std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_et_trigrams();

std::tuple<size_t, size_t, size_t> get_et_n_words();

} // namespace profiles

