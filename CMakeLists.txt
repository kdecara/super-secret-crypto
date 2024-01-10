cmake_minimum_required(VERSION 3.12)
project(rsa)

#path to source files
include_directories(src)

#define source files
set(SOURCES src/rsa.cpp)

#path to headers
include_directories(inc)

#define header files
set(HEADERS inc/rsa.h)

#path to test files
include_directories(tests)

#define test source files
set(TEST_SOURCES tests/rsa_tests.cpp)

#create an executable
add_executable(rsa_tests ${SOURCES} ${HEADERS} ${TEST_SOURCES})

#Link against google test
target_link_libraries(rsa_tests gtest gtest_main)
