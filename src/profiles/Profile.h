#pragma once
#include <unordered_map>
#include <tuple>
#include <string>
#include "profiles/ar.h"
#include "profiles/de.h"
#include "profiles/en.h"
#include "profiles/es.h"
#include "profiles/fr.h"
#include "profiles/it.h"
#include "profiles/ru.h"
#include "util/Language.h"
#include <memory>

namespace profiles {

class ProfileGroup;

class Profile {
 protected:
  util::Language lang_;
  std::unordered_map<uint32_t, size_t> oneGrams_;
  std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> bigrams_;
  std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> trigrams_;
  std::tuple<uint32_t, uint32_t, uint32_t> nWords_;
  Profile(){}
 public:
  friend class ProfileGroup;
  util::Language getLanguage() {
    return lang_;
  }
  std::string getLanguageString() {
    return util::stringOfLanguage(lang_);
  }
  static std::shared_ptr<Profile> loadRussian();
  static std::shared_ptr<Profile> loadEnglish();
  static std::shared_ptr<Profile> loadSpanish();
  static std::shared_ptr<Profile> loadGerman();
  static std::shared_ptr<Profile> loadFrench();
  static std::shared_ptr<Profile> loadItalian();
  static std::shared_ptr<Profile> loadArabic();
};

}