#include <memory>
#include "util/Language.h"

namespace langdetectpp {

namespace detection {
  class DetectorImpl;
}

class Detector {
protected:
  std::unique_ptr<detection::DetectorImpl> pImpl_;
  Detector(std::unique_ptr<detection::DetectorImpl>);
public:
  util::Language detect(const std::string&);
  static std::shared_ptr<Detector> create();
};

} // langdetectpp