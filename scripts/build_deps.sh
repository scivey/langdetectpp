#!/bin/bash

GTEST_DIR=`pwd`/external/googletest/googletest
GMOCK_DIR=`pwd`/external/googletest/googlemock

if [ ! -e "${GTEST_DIR}/build/libgtest.a" ]; then
    cd $GTEST_DIR && \
        mkdir -p build && \
        cd build && \
        cmake ../ && \
        make gtest && \
        make gtest_main;
fi


if [ ! -e "${GMOCK_DIR}/build/libgmock.a" ]; then
    cd $GMOCK_DIR && \
        mkdir -p build && \
        cd build && \
        cmake ../ && \
        make gmock && \
        make gmock_main;
fi
