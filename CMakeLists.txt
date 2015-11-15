cmake_minimum_required(VERSION 2.8)

project(data_structures)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLibs)

include(CheckCXXCompilerFlag)
include(AddCXXCompilerFlag)


add_cxx_compiler_flag(--std=c++11)
add_cxx_compiler_flag(-Wall)
if (DEFINED USING_CLANG)
    add_cxx_compiler_flag(-stdlib=libstdc++)
endif()


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googlemock/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mirror_utf8cpp/source
    /usr/local/include
)

set(GTEST_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googletest/build/libgtest.a
)

set(GMOCK_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googlemock/build/libgmock.a
)

link_directories(/usr/local/lib)

set(COMMON_LINK_LIBS
    folly
    wangle
    boost_thread
    boost_system
    boost_filesystem
    glog
    gflags
    atomic
    pthread
)

set(TEST_LIBS
    ${GTEST_LIB}
    ${GMOCK_LIB}
    ${COMMON_LINK_LIBS}
)

set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Language.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Detector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/Profile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ProfileGroup.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/detection/DetectionRunner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ngrams/NGramExtractor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/af.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/bg.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/bn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ca.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/cs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/cy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/da.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/de.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/el.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/en.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/es.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/et.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/fa.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/fi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/fr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/gu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/he.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/hi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/hr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/hu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/id.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/it.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ja.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/kn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ko.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/lt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/lv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/mk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ml.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/mr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ne.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/nl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/no.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/pa.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/pl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/pt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ro.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ru.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/sk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/sl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/so.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/sq.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/sv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/sw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ta.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/te.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/th.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/tl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/tr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/uk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/ur.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/vi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/zh_cn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/langs/zh_tw.cpp
)

add_library(langdetectpp
    ${LIB_SOURCES}
)
target_link_libraries(langdetectpp ${COMMON_LINK_LIBS})

set(RUNNER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(runner
    ${RUNNER_SOURCES}
)

add_dependencies(runner langdetectpp)
target_link_libraries(runner langdetectpp ${COMMON_LINK_LIBS})
