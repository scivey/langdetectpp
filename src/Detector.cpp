#include <memory>
#include <string>

#include <langdetectpp/Detector.h>
#include <langdetectpp/Language.h>
#include "detection/DetectorImpl.h"
#include "profiles/ProfileGroup.h"

using namespace std;
using langdetectpp::detection::DetectorImpl;
using langdetectpp::profiles::ProfileGroup;

namespace langdetectpp {
  Detector::Detector(unique_ptr<DetectorImpl> pImpl): pImpl_(std::move(pImpl)) {}

  Language Detector::detect(const string &text) {
    return pImpl_->detect(text);
  }

  shared_ptr<Detector> Detector::create() {
    auto profGroup = ProfileGroup::create();
    unique_ptr<DetectorImpl> pImpl(new DetectorImpl(profGroup));
    return shared_ptr<Detector>(new Detector(std::move(pImpl)));
  }
}