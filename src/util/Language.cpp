#include "util/Language.h"
#include <string>

namespace util {

std::string stringOfLanguage(Language lang) {
  if (lang == Language::DE) return "DE";
  if (lang == Language::EN) return "EN";
  if (lang == Language::ES) return "ES";
  if (lang == Language::FR) return "FR";
  if (lang == Language::IT) return "IT";
  if (lang == Language::RU) return "RU";
  if (lang == Language::AR) return "AR";
  return "UNKNOWN";
}

} // util
