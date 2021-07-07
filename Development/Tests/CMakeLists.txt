cmake_minimum_required(VERSION 3.8)

INCLUDE_DIRECTORIES("${BASEPATH}")

add_subdirectory(./gtest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

#add_library(test_stdafx INTERFACE)
#target_include_directories(test_stdafx INTERFACE test_stdafx.h)

add_executable(tests "test.cpp" )

target_link_libraries(tests gtest gtest_main)

add_test(NAME that-test-I-made COMMAND tests)

add_test(that-other-test-I-made tests)