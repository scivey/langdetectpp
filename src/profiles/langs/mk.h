#pragma once
#include <unordered_map>
#include <tuple>
#include <folly/Hash.h>

namespace langdetectpp { namespace profiles { namespace langs {

std::unordered_map<uint32_t, size_t> get_mk_one_grams();

std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> get_mk_bigrams();

std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> get_mk_trigrams();

std::tuple<size_t, size_t, size_t> get_mk_n_words();

}}} // langdetectpp::profiles::langs

