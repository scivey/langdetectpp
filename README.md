## langdetectpp

C++ port of the Java [https://github.com/shuyo/language-detection](language-detection) library.

It analyzes UTF8-encoded text and returns the most likely human language of the contents.

It uses the same language profiles as the original library, which are based on 1-3 character N-grams.  These profiles cover 55 different language.

```c++
#include <string>
#include <iostream>
#include <langdetectpp/langdetectpp>

using langdetectpp::Detector;
using langdetectpp::Language;
using std::string;
using std::cout;

int main() {
    auto detector = Detector::create();
    string someEnglishText = "Some english text to analyze.";
    Language lang = detector->detect(someEnglishText);
    cout << langdetectpp::stringOfLanguage(lang) << std::endl;

    string someGermanText = "Im Rahmen der Trainingskontrollen k\u00f6nnen etwa 8.650 Kaderathleten gepr\u00fcft werden, die in drei Testpools aufgeteilt sind und an nationalen und internationalen Wettk\u00e4mpfen teilnehmen.";
    lang = detector->detect(someGermanText);
    cout << langdetectpp::stringOfLanguage(lang) << std::endl;
}
```

```bash
EN
DE
```

### building

```bash
mkdir build
cd build
cmake ../
make
```

### usage
The main public-facing part of this library is the `Detector` class.  This class is instantiated through the `Detector::create()` static method, which returns a `shared_ptr`.
Initializing a `Detector` is relatively expensive because it needs to build up the initial ngram vs language score matrix.  Because of this, a `Detector` instance should be kept around and reused.

`Detector` is thread-safe and has no mutable state.  You should only need a single instance for anything.

The most likely language for a given string is returned as a `langdetect::Language`, which is an enum class.  There is a utility method for getting the string of the corresponding language code:

```c++
std::string stringOfLanguage(langdetectpp::Language);
```

```c++
    auto lang = langdetectpp::Language::EN;
    string langName = langdetectpp::stringofLanguage(lang);
```

There is also a utility method for getting the English name of the language code:

```c++
std::string englishNameOfLanguage(langdetectpp::Language)
```

```c++
    auto lang = langdetectpp::Language::AR;
    string langName = langdetectpp::englishNameOfLanguage(lang);
    cout << langName << endl;
    // "Arabic"
```
