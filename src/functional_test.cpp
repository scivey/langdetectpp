#include <cassert>
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
#include <langdetectpp/langdetectpp.h>
using namespace std;
namespace bfs = boost::filesystem;
using langdetectpp::Language;
int main() {
  vector<pair<string, Language>> files {
    {"ar_from_wikipedia.txt", Language::AR},
    {"en_jezebel.txt", Language::EN},
    {"ru_from_wikipedia.txt", Language::RU},
    {"de_from_wikipedia.txt", Language::DE},
    {"fr_from_wikipedia.txt", Language::FR},
    {"es_from_wikipedia.txt", Language::ES}
  };

  size_t maxLen = 0;
  for (auto &elem: files) {
    auto fname = elem.first;
    if (fname.size() > maxLen) {
      maxLen = fname.size();
    }
  }
  auto detector = langdetectpp::Detector::create();
  bfs::path basePath = bfs::canonical("./../text");
  for (auto &elem: files) {
    string fname = elem.first;
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
    LOG(INFO) << logLine.str() << "  ->  " << langdetectpp::englishNameOfLanguage(lang);
    assert(elem.second == lang);
  }
}
