#pragma once

#include <memory>
#include "ngrams/NGramExtractor.h"
#include <langdetectpp/Language.h>
#include "profiles/ProfileGroup.h"
#include "detection/DetectionRunner.h"

namespace langdetectpp { namespace detection {

class DetectorImpl {
 protected:
  std::shared_ptr<profiles::ProfileGroup> profileGroup_;
 public:
  DetectorImpl(std::shared_ptr<profiles::ProfileGroup> profileGroup)
    : profileGroup_(profileGroup){}
  Language detect(const std::string &text) {
    ngrams::NGramExtractor extractor(text);
    auto extracted = extractor.extract();
    DetectionRunner runner(profileGroup_, extracted);
    return runner.detect();
  }
};

}} // langdetectpp::detection
