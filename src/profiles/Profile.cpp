#include "profiles/Profile.h"
#include <memory>
#include "profiles/langs/ar.h"
#include "profiles/langs/de.h"
#include "profiles/langs/en.h"
#include "profiles/langs/es.h"
#include "profiles/langs/fr.h"
#include "profiles/langs/it.h"
#include "profiles/langs/ru.h"

using namespace std;

namespace langdetectpp { namespace profiles {

shared_ptr<Profile> Profile::loadRussian() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::RU;
  result->oneGrams_ = langs::get_ru_one_grams();
  result->bigrams_ = langs::get_ru_bigrams();
  result->trigrams_ = langs::get_ru_trigrams();
  result->nWords_ = langs::get_ru_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEnglish() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::EN;
  result->oneGrams_ = langs::get_en_one_grams();
  result->bigrams_ = langs::get_en_bigrams();
  result->trigrams_ = langs::get_en_trigrams();
  result->nWords_ = langs::get_en_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSpanish() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::ES;
  result->oneGrams_ = langs::get_es_one_grams();
  result->bigrams_ = langs::get_es_bigrams();
  result->trigrams_ = langs::get_es_trigrams();
  result->nWords_ = langs::get_es_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadGerman() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::DE;
  result->oneGrams_ = langs::get_de_one_grams();
  result->bigrams_ = langs::get_de_bigrams();
  result->trigrams_ = langs::get_de_trigrams();
  result->nWords_ = langs::get_de_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadFrench() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::FR;
  result->oneGrams_ = langs::get_fr_one_grams();
  result->bigrams_ = langs::get_fr_bigrams();
  result->trigrams_ = langs::get_fr_trigrams();
  result->nWords_ = langs::get_fr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadItalian() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::IT;
  result->oneGrams_ = langs::get_it_one_grams();
  result->bigrams_ = langs::get_it_bigrams();
  result->trigrams_ = langs::get_it_trigrams();
  result->nWords_ = langs::get_it_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadArabic() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::AR;
  result->oneGrams_ = langs::get_ar_one_grams();
  result->bigrams_ = langs::get_ar_bigrams();
  result->trigrams_ = langs::get_ar_trigrams();
  result->nWords_ = langs::get_ar_n_words();
  return result;
}

}} // langdetectpp::profiles