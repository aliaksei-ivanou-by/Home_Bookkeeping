cmake_minimum_required(VERSION 3.8)

INCLUDE_DIRECTORIES("${BASEPATH}")

add_executable(test_main "test_main.cpp")

target_link_libraries(test_main gtest gtest_main)
