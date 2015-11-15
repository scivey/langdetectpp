#include <langdetectpp/Language.h>
#include <string>

namespace langdetectpp {

std::string stringOfLanguage(Language lang) {
  switch(lang) {
    case Language::AF : return "AF";
    case Language::AR : return "AR";
    case Language::BG : return "BG";
    case Language::BN : return "BN";
    case Language::CA : return "CA";
    case Language::CS : return "CS";
    case Language::CY : return "CY";
    case Language::DA : return "DA";
    case Language::DE : return "DE";
    case Language::EL : return "EL";
    case Language::EN : return "EN";
    case Language::ES : return "ES";
    case Language::ET : return "ET";
    case Language::FA : return "FA";
    case Language::FI : return "FI";
    case Language::FR : return "FR";
    case Language::GU : return "GU";
    case Language::HE : return "HE";
    case Language::HI : return "HI";
    case Language::HR : return "HR";
    case Language::HU : return "HU";
    case Language::ID : return "ID";
    case Language::IT : return "IT";
    case Language::JA : return "JA";
    case Language::KN : return "KN";
    case Language::KO : return "KO";
    case Language::LT : return "LT";
    case Language::LV : return "LV";
    case Language::MK : return "MK";
    case Language::ML : return "ML";
    case Language::MR : return "MR";
    case Language::NE : return "NE";
    case Language::NL : return "NL";
    case Language::NO : return "NO";
    case Language::PA : return "PA";
    case Language::PL : return "PL";
    case Language::PT : return "PT";
    case Language::RO : return "RO";
    case Language::RU : return "RU";
    case Language::SK : return "SK";
    case Language::SL : return "SL";
    case Language::SO : return "SO";
    case Language::SQ : return "SQ";
    case Language::SV : return "SV";
    case Language::SW : return "SW";
    case Language::TA : return "TA";
    case Language::TE : return "TE";
    case Language::TH : return "TH";
    case Language::TL : return "TL";
    case Language::TR : return "TR";
    case Language::UK : return "UK";
    case Language::UNKNOWN : return "UNKNOWN";
    case Language::UR : return "UR";
    case Language::VI : return "VI";
    case Language::ZH_CN : return "ZH_CN";
    case Language::ZH_TW : return "ZH_TW";
    default : return "NOT_RECOGNIZED";
  }
}

std::string englishNameOfLanguage(Language lang) {
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

} // langdetectpp