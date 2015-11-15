#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <memory>
#include <unordered_map>
#include <folly/FileUtil.h>
#include <folly/Conv.h>
#include <folly/Hash.h>
#include <folly/Format.h>

#include <glog/logging.h>
#include <boost/filesystem.hpp>
#include "utf8.h"
#include "profiles/Profile.h"
#include "profiles/ProfileGroup.h"
#include "util/CircleArray.h"
#include "util/misc.h"
#include "util/Language.h"
#include "ngrams/NGramExtractor.h"
#include "detection/Detector.h"
using namespace std;

int main() {
  vector<string> files {
    "/home/scott/fbcode/data_structures/text/ar_from_wikipedia.txt",
    "/home/scott/fbcode/data_structures/text/en_jezebel.txt",
    "/home/scott/fbcode/data_structures/text/ru_from_wikipedia.txt",
    "/home/scott/fbcode/data_structures/text/de_from_wikipedia.txt",
    "/home/scott/fbcode/data_structures/text/fr_from_wikipedia.txt",
    "/home/scott/fbcode/data_structures/text/es_from_wikipedia.txt"
  };
  auto pgroup = profiles::ProfileGroup::create();
  detection::Detector detector(pgroup);
  for (string fname: files) {
    string data;
    folly::readFile(fname.c_str(), data);
    // LOG(INFO) << data;
    util::Language lang = detector.detect(data);
    LOG(INFO) << fname << "\t->\t" << util::stringOfLanguage(lang);

  }
}
