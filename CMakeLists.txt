cmake_minimum_required(VERSION 2.8)

project(data_structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --stdlib=libstdc++")


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    /usr/include
    /usr/local/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googlemock/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mirror_utf8cpp/source
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

set(RUNNER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/util/Language.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/Profile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ProfileGroup.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/detection/DetectionRunner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ngrams/NGramExtractor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/af.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/bg.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/bn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ca.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/cs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/cy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/da.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/de.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/el.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/en.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/es.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/et.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/fa.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/fi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/fr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/gu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/he.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/hi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/hr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/hu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/id.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/it.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ja.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/kn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ko.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/lt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/lv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/mk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ml.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/mr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ne.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/nl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/no.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/pa.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/pl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/pt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ro.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ru.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/sl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/so.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/sq.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/sv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/sw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ta.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/te.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/th.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/tl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/tr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/uk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/ur.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/vi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/zh_cn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/profiles/zh_tw.cpp
)

add_executable(runner ${RUNNER_SOURCES})
target_link_libraries(runner
    ${COMMON_LINK_LIBS}
)
