#pragma once
#include <unordered_map>
#include <tuple>
#include <folly/Hash.h>

namespace profiles {

std::unordered_map<uint32_t, size_t> get_pt_one_grams();

std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_pt_bigrams();

std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_pt_trigrams();

std::tuple<size_t, size_t, size_t> get_pt_n_words();

} // namespace profiles

