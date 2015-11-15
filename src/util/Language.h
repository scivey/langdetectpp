#pragma once
#include <string>

namespace langdetectpp { namespace util {

enum class Language {
  AR, DE, EN, ES, FR, IT, RU
};

std::string stringOfLanguage(Language lang);

std::string englishLanguageName(Language lang);


}} // langdetectpp::util