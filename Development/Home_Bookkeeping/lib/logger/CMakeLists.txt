cmake_minimum_required(VERSION 3.8)

project(logger)

include_directories(Appenders)
add_subdirectory(Appenders)

include_directories(Converters)
add_subdirectory(Converters)

include_directories(Formatters)
add_subdirectory(Formatters)

include_directories(Initializers)
add_subdirectory(Initializers)

add_library(logger INTERFACE)
target_include_directories(logger INTERFACE .)
