#pragma once
#include <string>

namespace util {

enum class Language {
  AR, DE, EN, ES, FR, IT, RU
};

std::string stringOfLanguage(Language lang);

} // util
