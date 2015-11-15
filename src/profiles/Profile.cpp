#include "profiles/Profile.h"
#include <memory>
#include "profiles/ar.h"
#include "profiles/de.h"
#include "profiles/en.h"
#include "profiles/es.h"
#include "profiles/fr.h"
#include "profiles/it.h"
#include "profiles/ru.h"

using namespace std;

namespace profiles {

shared_ptr<Profile> Profile::loadRussian() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::RU;
  result->oneGrams_ = get_ru_one_grams();
  result->bigrams_ = get_ru_bigrams();
  result->trigrams_ = get_ru_trigrams();
  result->nWords_ = get_ru_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEnglish() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::EN;
  result->oneGrams_ = get_en_one_grams();
  result->bigrams_ = get_en_bigrams();
  result->trigrams_ = get_en_trigrams();
  result->nWords_ = get_en_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSpanish() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::ES;
  result->oneGrams_ = get_es_one_grams();
  result->bigrams_ = get_es_bigrams();
  result->trigrams_ = get_es_trigrams();
  result->nWords_ = get_es_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadGerman() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::DE;
  result->oneGrams_ = get_de_one_grams();
  result->bigrams_ = get_de_bigrams();
  result->trigrams_ = get_de_trigrams();
  result->nWords_ = get_de_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadFrench() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::FR;
  result->oneGrams_ = get_fr_one_grams();
  result->bigrams_ = get_fr_bigrams();
  result->trigrams_ = get_fr_trigrams();
  result->nWords_ = get_fr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadItalian() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::IT;
  result->oneGrams_ = get_it_one_grams();
  result->bigrams_ = get_it_bigrams();
  result->trigrams_ = get_it_trigrams();
  result->nWords_ = get_it_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadArabic() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = util::Language::AR;
  result->oneGrams_ = get_ar_one_grams();
  result->bigrams_ = get_ar_bigrams();
  result->trigrams_ = get_ar_trigrams();
  result->nWords_ = get_ar_n_words();
  return result;
}

} // profiles