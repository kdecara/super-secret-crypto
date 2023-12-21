cmake_minimum_required(VERSION 3.12)
project(gf)

#path to source files
include_directories(src)

#define source files
set(SOURCES src/gf.cpp)

#path to headers
include_directories(inc)

#define header files
set(HEADERS inc/gf.h)

#path to test files
include_directories(tests)

#define test source files
set(TEST_SOURCES tests/gf_tests.cpp)

#create an executable
add_executable(gf_tests ${SOURCES} ${HEADERS} ${TEST_SOURCES})

#Link against google test
target_link_libraries(gf_tests gtest gtest_main)
