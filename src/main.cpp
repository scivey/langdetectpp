#include <string>
#include <sstream>

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
#include "Language.h"
#include "ngrams/NGramExtractor.h"
#include "Detector.h"
using namespace std;
namespace bfs = boost::filesystem;
int main() {
  vector<string> files {
    "ar_from_wikipedia.txt",
    "en_jezebel.txt",
    "ru_from_wikipedia.txt",
    "de_from_wikipedia.txt",
    "fr_from_wikipedia.txt",
    "es_from_wikipedia.txt"
  };

  size_t maxLen = 0;
  for (auto &elem: files) {
    if (elem.size() > maxLen) {
      maxLen = elem.size();
    }
  }
  auto detector = langdetectpp::Detector::create();
  bfs::path basePath = bfs::canonical("./../text");
  for (string fname: files) {
    bfs::path filePath = basePath / fname;
    string strPath = filePath.string();
    string data;
    folly::readFile(strPath.c_str(), data);
    // LOG(INFO) << data;
    auto lang = detector->detect(data);

    ostringstream logLine;
    logLine << fname;
    for (size_t i = fname.size(); i < maxLen; i++) {
      logLine << " ";
    }
    LOG(INFO) << logLine.str() << "  ->  " << langdetectpp::englishLanguageName(lang);
  }
}
