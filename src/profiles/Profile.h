#pragma once
#include <unordered_map>
#include <tuple>
#include <string>
#include <langdetectpp/Language.h>
#include <folly/Hash.h>
#include <memory>

namespace langdetectpp { namespace profiles {

class ProfileGroup;

class Profile {
 protected:
  Language lang_;
  std::unordered_map<uint32_t, size_t> oneGrams_;
  std::unordered_map<std::tuple<uint32_t, uint32_t>, size_t> bigrams_;
  std::unordered_map<std::tuple<uint32_t, uint32_t, uint32_t>, size_t> trigrams_;
  std::tuple<uint32_t, uint32_t, uint32_t> nWords_;
  Profile(){}
 public:
  friend class ProfileGroup;
  Language getLanguage() {
    return lang_;
  }
  std::string getLanguageString() {
    return stringOfLanguage(lang_);
  }

  static std::shared_ptr<Profile> loadAf();
  static std::shared_ptr<Profile> loadAr();
  static std::shared_ptr<Profile> loadBg();
  static std::shared_ptr<Profile> loadBn();
  static std::shared_ptr<Profile> loadCa();
  static std::shared_ptr<Profile> loadCs();
  static std::shared_ptr<Profile> loadCy();
  static std::shared_ptr<Profile> loadDa();
  static std::shared_ptr<Profile> loadDe();
  static std::shared_ptr<Profile> loadEl();
  static std::shared_ptr<Profile> loadEn();
  static std::shared_ptr<Profile> loadEs();
  static std::shared_ptr<Profile> loadEt();
  static std::shared_ptr<Profile> loadFa();
  static std::shared_ptr<Profile> loadFi();
  static std::shared_ptr<Profile> loadFr();
  static std::shared_ptr<Profile> loadGu();
  static std::shared_ptr<Profile> loadHe();
  static std::shared_ptr<Profile> loadHi();
  static std::shared_ptr<Profile> loadHr();
  static std::shared_ptr<Profile> loadHu();
  static std::shared_ptr<Profile> loadId();
  static std::shared_ptr<Profile> loadIt();
  static std::shared_ptr<Profile> loadJa();
  static std::shared_ptr<Profile> loadKn();
  static std::shared_ptr<Profile> loadKo();
  static std::shared_ptr<Profile> loadLv();
  static std::shared_ptr<Profile> loadLt();
  static std::shared_ptr<Profile> loadMk();
  static std::shared_ptr<Profile> loadMl();
  static std::shared_ptr<Profile> loadMr();
  static std::shared_ptr<Profile> loadNe();
  static std::shared_ptr<Profile> loadNl();
  static std::shared_ptr<Profile> loadNo();
  static std::shared_ptr<Profile> loadPa();
  static std::shared_ptr<Profile> loadPl();
  static std::shared_ptr<Profile> loadPt();
  static std::shared_ptr<Profile> loadRo();
  static std::shared_ptr<Profile> loadRu();
  static std::shared_ptr<Profile> loadSk();
  static std::shared_ptr<Profile> loadSl();
  static std::shared_ptr<Profile> loadSo();
  static std::shared_ptr<Profile> loadSq();
  static std::shared_ptr<Profile> loadSv();
  static std::shared_ptr<Profile> loadSw();
  static std::shared_ptr<Profile> loadTa();
  static std::shared_ptr<Profile> loadTe();
  static std::shared_ptr<Profile> loadTh();
  static std::shared_ptr<Profile> loadTl();
  static std::shared_ptr<Profile> loadTr();
  static std::shared_ptr<Profile> loadUk();
  static std::shared_ptr<Profile> loadUr();
  static std::shared_ptr<Profile> loadVi();
  static std::shared_ptr<Profile> loadZhCn();
  static std::shared_ptr<Profile> loadZhTw();
};

}} // langdetectpp::profiles
