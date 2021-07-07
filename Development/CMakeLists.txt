cmake_minimum_required (VERSION 3.8)

project ("Home_Bookkeeping")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

add_subdirectory ("Home_Bookkeeping")

add_subdirectory ("Tests")