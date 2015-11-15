#include "profiles/Profile.h"
#include <memory>
#include "profiles/langs/af.h"
#include "profiles/langs/ar.h"
#include "profiles/langs/bg.h"
#include "profiles/langs/bn.h"
#include "profiles/langs/ca.h"
#include "profiles/langs/cs.h"
#include "profiles/langs/cy.h"
#include "profiles/langs/da.h"
#include "profiles/langs/de.h"
#include "profiles/langs/el.h"
#include "profiles/langs/en.h"
#include "profiles/langs/es.h"
#include "profiles/langs/et.h"
#include "profiles/langs/fa.h"
#include "profiles/langs/fi.h"
#include "profiles/langs/fr.h"
#include "profiles/langs/gu.h"
#include "profiles/langs/he.h"
#include "profiles/langs/hi.h"
#include "profiles/langs/hr.h"
#include "profiles/langs/hu.h"
#include "profiles/langs/id.h"
#include "profiles/langs/it.h"
#include "profiles/langs/ja.h"
#include "profiles/langs/kn.h"
#include "profiles/langs/ko.h"
#include "profiles/langs/lt.h"
#include "profiles/langs/lv.h"
#include "profiles/langs/mk.h"
#include "profiles/langs/ml.h"
#include "profiles/langs/mr.h"
#include "profiles/langs/ne.h"
#include "profiles/langs/nl.h"
#include "profiles/langs/no.h"
#include "profiles/langs/pa.h"
#include "profiles/langs/pl.h"
#include "profiles/langs/pt.h"
#include "profiles/langs/ro.h"
#include "profiles/langs/ru.h"
#include "profiles/langs/sk.h"
#include "profiles/langs/sl.h"
#include "profiles/langs/so.h"
#include "profiles/langs/sq.h"
#include "profiles/langs/sv.h"
#include "profiles/langs/sw.h"
#include "profiles/langs/ta.h"
#include "profiles/langs/te.h"
#include "profiles/langs/th.h"
#include "profiles/langs/tl.h"
#include "profiles/langs/tr.h"
#include "profiles/langs/uk.h"
#include "profiles/langs/ur.h"
#include "profiles/langs/vi.h"
#include "profiles/langs/zh_cn.h"
#include "profiles/langs/zh_tw.h"


using namespace std;

namespace langdetectpp { namespace profiles {

shared_ptr<Profile> Profile::loadAf() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::AF;
  result->oneGrams_ = langs::get_af_one_grams();
  result->bigrams_ = langs::get_af_bigrams();
  result->trigrams_ = langs::get_af_trigrams();
  result->nWords_ = langs::get_af_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadAr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::AR;
  result->oneGrams_ = langs::get_ar_one_grams();
  result->bigrams_ = langs::get_ar_bigrams();
  result->trigrams_ = langs::get_ar_trigrams();
  result->nWords_ = langs::get_ar_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadBg() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::BG;
  result->oneGrams_ = langs::get_bg_one_grams();
  result->bigrams_ = langs::get_bg_bigrams();
  result->trigrams_ = langs::get_bg_trigrams();
  result->nWords_ = langs::get_bg_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadBn() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::BN;
  result->oneGrams_ = langs::get_bn_one_grams();
  result->bigrams_ = langs::get_bn_bigrams();
  result->trigrams_ = langs::get_bn_trigrams();
  result->nWords_ = langs::get_bn_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadCa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::CA;
  result->oneGrams_ = langs::get_ca_one_grams();
  result->bigrams_ = langs::get_ca_bigrams();
  result->trigrams_ = langs::get_ca_trigrams();
  result->nWords_ = langs::get_ca_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadCs() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::CS;
  result->oneGrams_ = langs::get_cs_one_grams();
  result->bigrams_ = langs::get_cs_bigrams();
  result->trigrams_ = langs::get_cs_trigrams();
  result->nWords_ = langs::get_cs_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadCy() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::CY;
  result->oneGrams_ = langs::get_cy_one_grams();
  result->bigrams_ = langs::get_cy_bigrams();
  result->trigrams_ = langs::get_cy_trigrams();
  result->nWords_ = langs::get_cy_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadDa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::DA;
  result->oneGrams_ = langs::get_da_one_grams();
  result->bigrams_ = langs::get_da_bigrams();
  result->trigrams_ = langs::get_da_trigrams();
  result->nWords_ = langs::get_da_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadDe() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::DE;
  result->oneGrams_ = langs::get_de_one_grams();
  result->bigrams_ = langs::get_de_bigrams();
  result->trigrams_ = langs::get_de_trigrams();
  result->nWords_ = langs::get_de_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::EL;
  result->oneGrams_ = langs::get_el_one_grams();
  result->bigrams_ = langs::get_el_bigrams();
  result->trigrams_ = langs::get_el_trigrams();
  result->nWords_ = langs::get_el_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEn() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::EN;
  result->oneGrams_ = langs::get_en_one_grams();
  result->bigrams_ = langs::get_en_bigrams();
  result->trigrams_ = langs::get_en_trigrams();
  result->nWords_ = langs::get_en_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEs() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ES;
  result->oneGrams_ = langs::get_es_one_grams();
  result->bigrams_ = langs::get_es_bigrams();
  result->trigrams_ = langs::get_es_trigrams();
  result->nWords_ = langs::get_es_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadEt() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ET;
  result->oneGrams_ = langs::get_et_one_grams();
  result->bigrams_ = langs::get_et_bigrams();
  result->trigrams_ = langs::get_et_trigrams();
  result->nWords_ = langs::get_et_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadFa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::FA;
  result->oneGrams_ = langs::get_fa_one_grams();
  result->bigrams_ = langs::get_fa_bigrams();
  result->trigrams_ = langs::get_fa_trigrams();
  result->nWords_ = langs::get_fa_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadFi() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::FI;
  result->oneGrams_ = langs::get_fi_one_grams();
  result->bigrams_ = langs::get_fi_bigrams();
  result->trigrams_ = langs::get_fi_trigrams();
  result->nWords_ = langs::get_fi_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadFr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::FR;
  result->oneGrams_ = langs::get_fr_one_grams();
  result->bigrams_ = langs::get_fr_bigrams();
  result->trigrams_ = langs::get_fr_trigrams();
  result->nWords_ = langs::get_fr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadGu() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::GU;
  result->oneGrams_ = langs::get_gu_one_grams();
  result->bigrams_ = langs::get_gu_bigrams();
  result->trigrams_ = langs::get_gu_trigrams();
  result->nWords_ = langs::get_gu_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadHe() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::HE;
  result->oneGrams_ = langs::get_he_one_grams();
  result->bigrams_ = langs::get_he_bigrams();
  result->trigrams_ = langs::get_he_trigrams();
  result->nWords_ = langs::get_he_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadHi() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::HI;
  result->oneGrams_ = langs::get_hi_one_grams();
  result->bigrams_ = langs::get_hi_bigrams();
  result->trigrams_ = langs::get_hi_trigrams();
  result->nWords_ = langs::get_hi_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadHr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::HR;
  result->oneGrams_ = langs::get_hr_one_grams();
  result->bigrams_ = langs::get_hr_bigrams();
  result->trigrams_ = langs::get_hr_trigrams();
  result->nWords_ = langs::get_hr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadHu() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::HU;
  result->oneGrams_ = langs::get_hu_one_grams();
  result->bigrams_ = langs::get_hu_bigrams();
  result->trigrams_ = langs::get_hu_trigrams();
  result->nWords_ = langs::get_hu_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadId() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ID;
  result->oneGrams_ = langs::get_id_one_grams();
  result->bigrams_ = langs::get_id_bigrams();
  result->trigrams_ = langs::get_id_trigrams();
  result->nWords_ = langs::get_id_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadIt() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::IT;
  result->oneGrams_ = langs::get_it_one_grams();
  result->bigrams_ = langs::get_it_bigrams();
  result->trigrams_ = langs::get_it_trigrams();
  result->nWords_ = langs::get_it_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadJa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::JA;
  result->oneGrams_ = langs::get_ja_one_grams();
  result->bigrams_ = langs::get_ja_bigrams();
  result->trigrams_ = langs::get_ja_trigrams();
  result->nWords_ = langs::get_ja_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadKn() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::KN;
  result->oneGrams_ = langs::get_kn_one_grams();
  result->bigrams_ = langs::get_kn_bigrams();
  result->trigrams_ = langs::get_kn_trigrams();
  result->nWords_ = langs::get_kn_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadKo() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::KO;
  result->oneGrams_ = langs::get_ko_one_grams();
  result->bigrams_ = langs::get_ko_bigrams();
  result->trigrams_ = langs::get_ko_trigrams();
  result->nWords_ = langs::get_ko_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadLt() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::LT;
  result->oneGrams_ = langs::get_lt_one_grams();
  result->bigrams_ = langs::get_lt_bigrams();
  result->trigrams_ = langs::get_lt_trigrams();
  result->nWords_ = langs::get_lt_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadLv() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::LV;
  result->oneGrams_ = langs::get_lv_one_grams();
  result->bigrams_ = langs::get_lv_bigrams();
  result->trigrams_ = langs::get_lv_trigrams();
  result->nWords_ = langs::get_lv_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadMk() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::MK;
  result->oneGrams_ = langs::get_mk_one_grams();
  result->bigrams_ = langs::get_mk_bigrams();
  result->trigrams_ = langs::get_mk_trigrams();
  result->nWords_ = langs::get_mk_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadMl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ML;
  result->oneGrams_ = langs::get_ml_one_grams();
  result->bigrams_ = langs::get_ml_bigrams();
  result->trigrams_ = langs::get_ml_trigrams();
  result->nWords_ = langs::get_ml_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadMr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::MR;
  result->oneGrams_ = langs::get_mr_one_grams();
  result->bigrams_ = langs::get_mr_bigrams();
  result->trigrams_ = langs::get_mr_trigrams();
  result->nWords_ = langs::get_mr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadNe() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::NE;
  result->oneGrams_ = langs::get_ne_one_grams();
  result->bigrams_ = langs::get_ne_bigrams();
  result->trigrams_ = langs::get_ne_trigrams();
  result->nWords_ = langs::get_ne_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadNl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::NL;
  result->oneGrams_ = langs::get_nl_one_grams();
  result->bigrams_ = langs::get_nl_bigrams();
  result->trigrams_ = langs::get_nl_trigrams();
  result->nWords_ = langs::get_nl_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadNo() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::NO;
  result->oneGrams_ = langs::get_no_one_grams();
  result->bigrams_ = langs::get_no_bigrams();
  result->trigrams_ = langs::get_no_trigrams();
  result->nWords_ = langs::get_no_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadPa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::PA;
  result->oneGrams_ = langs::get_pa_one_grams();
  result->bigrams_ = langs::get_pa_bigrams();
  result->trigrams_ = langs::get_pa_trigrams();
  result->nWords_ = langs::get_pa_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadPl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::PL;
  result->oneGrams_ = langs::get_pl_one_grams();
  result->bigrams_ = langs::get_pl_bigrams();
  result->trigrams_ = langs::get_pl_trigrams();
  result->nWords_ = langs::get_pl_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadPt() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::PT;
  result->oneGrams_ = langs::get_pt_one_grams();
  result->bigrams_ = langs::get_pt_bigrams();
  result->trigrams_ = langs::get_pt_trigrams();
  result->nWords_ = langs::get_pt_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadRo() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::RO;
  result->oneGrams_ = langs::get_ro_one_grams();
  result->bigrams_ = langs::get_ro_bigrams();
  result->trigrams_ = langs::get_ro_trigrams();
  result->nWords_ = langs::get_ro_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadRu() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::RU;
  result->oneGrams_ = langs::get_ru_one_grams();
  result->bigrams_ = langs::get_ru_bigrams();
  result->trigrams_ = langs::get_ru_trigrams();
  result->nWords_ = langs::get_ru_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSk() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SK;
  result->oneGrams_ = langs::get_sk_one_grams();
  result->bigrams_ = langs::get_sk_bigrams();
  result->trigrams_ = langs::get_sk_trigrams();
  result->nWords_ = langs::get_sk_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SL;
  result->oneGrams_ = langs::get_sl_one_grams();
  result->bigrams_ = langs::get_sl_bigrams();
  result->trigrams_ = langs::get_sl_trigrams();
  result->nWords_ = langs::get_sl_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSo() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SO;
  result->oneGrams_ = langs::get_so_one_grams();
  result->bigrams_ = langs::get_so_bigrams();
  result->trigrams_ = langs::get_so_trigrams();
  result->nWords_ = langs::get_so_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSq() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SQ;
  result->oneGrams_ = langs::get_sq_one_grams();
  result->bigrams_ = langs::get_sq_bigrams();
  result->trigrams_ = langs::get_sq_trigrams();
  result->nWords_ = langs::get_sq_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSv() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SV;
  result->oneGrams_ = langs::get_sv_one_grams();
  result->bigrams_ = langs::get_sv_bigrams();
  result->trigrams_ = langs::get_sv_trigrams();
  result->nWords_ = langs::get_sv_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadSw() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::SW;
  result->oneGrams_ = langs::get_sw_one_grams();
  result->bigrams_ = langs::get_sw_bigrams();
  result->trigrams_ = langs::get_sw_trigrams();
  result->nWords_ = langs::get_sw_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadTa() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::TA;
  result->oneGrams_ = langs::get_ta_one_grams();
  result->bigrams_ = langs::get_ta_bigrams();
  result->trigrams_ = langs::get_ta_trigrams();
  result->nWords_ = langs::get_ta_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadTe() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::TE;
  result->oneGrams_ = langs::get_te_one_grams();
  result->bigrams_ = langs::get_te_bigrams();
  result->trigrams_ = langs::get_te_trigrams();
  result->nWords_ = langs::get_te_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadTh() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::TH;
  result->oneGrams_ = langs::get_th_one_grams();
  result->bigrams_ = langs::get_th_bigrams();
  result->trigrams_ = langs::get_th_trigrams();
  result->nWords_ = langs::get_th_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadTl() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::TL;
  result->oneGrams_ = langs::get_tl_one_grams();
  result->bigrams_ = langs::get_tl_bigrams();
  result->trigrams_ = langs::get_tl_trigrams();
  result->nWords_ = langs::get_tl_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadTr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::TR;
  result->oneGrams_ = langs::get_tr_one_grams();
  result->bigrams_ = langs::get_tr_bigrams();
  result->trigrams_ = langs::get_tr_trigrams();
  result->nWords_ = langs::get_tr_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadUk() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::UK;
  result->oneGrams_ = langs::get_uk_one_grams();
  result->bigrams_ = langs::get_uk_bigrams();
  result->trigrams_ = langs::get_uk_trigrams();
  result->nWords_ = langs::get_uk_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadUr() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::UR;
  result->oneGrams_ = langs::get_ur_one_grams();
  result->bigrams_ = langs::get_ur_bigrams();
  result->trigrams_ = langs::get_ur_trigrams();
  result->nWords_ = langs::get_ur_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadVi() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::VI;
  result->oneGrams_ = langs::get_vi_one_grams();
  result->bigrams_ = langs::get_vi_bigrams();
  result->trigrams_ = langs::get_vi_trigrams();
  result->nWords_ = langs::get_vi_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadZhCn() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ZH_CN;
  result->oneGrams_ = langs::get_zh_cn_one_grams();
  result->bigrams_ = langs::get_zh_cn_bigrams();
  result->trigrams_ = langs::get_zh_cn_trigrams();
  result->nWords_ = langs::get_zh_cn_n_words();
  return result;
}

shared_ptr<Profile> Profile::loadZhTw() {
  shared_ptr<Profile> result(new Profile);
  result->lang_ = Language::ZH_TW;
  result->oneGrams_ = langs::get_zh_tw_one_grams();
  result->bigrams_ = langs::get_zh_tw_bigrams();
  result->trigrams_ = langs::get_zh_tw_trigrams();
  result->nWords_ = langs::get_zh_tw_n_words();
  return result;
}

}} // langdetectpp::profiles