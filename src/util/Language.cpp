#include "util/Language.h"
#include <string>

namespace langdetectpp { namespace util {

std::string stringOfLanguage(Language lang) {
  switch (lang) {
    case Language::AR : return "AR";
    case Language::DE : return "DE";
    case Language::EN : return "EN";
    case Language::ES : return "ES";
    case Language::FR : return "FR";
    case Language::IT : return "IT";
    case Language::RU : return "RU";
    default           : return "UNKNOWN";
  }
}

std::string englishLanguageName(Language lang) {
  switch (lang) {
    case Language::AR : return "Arabic";
    case Language::DE : return "German";
    case Language::EN : return "English";
    case Language::ES : return "Spanish";
    case Language::FR : return "French";
    case Language::IT : return "Italian";
    case Language::RU : return "Russian";
    default           : return "UNKNOWN";
  }
}

}} // langdetectpp::util