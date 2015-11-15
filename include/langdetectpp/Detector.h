#pragma once
#include <memory>
#include "Language.h"

namespace langdetectpp {

namespace detection {
  class DetectorImpl;
}

class Detector {
protected:
  std::unique_ptr<detection::DetectorImpl> pImpl_;
  Detector(std::unique_ptr<detection::DetectorImpl>);
public:
  Language detect(const std::string&);
  static std::shared_ptr<Detector> create();
};

} // langdetectpp