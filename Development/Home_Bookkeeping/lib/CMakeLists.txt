cmake_minimum_required(VERSION 3.8)

project(lib)

include_directories(constants)
add_subdirectory(constants)

include_directories(sqlite)
add_subdirectory(sqlite)

include_directories(logger)
add_subdirectory(logger)

include_directories(enum)
add_subdirectory(enum)
