cmake_minimum_required(VERSION 3.8)

project(constants)

add_library(constants INTERFACE)
target_include_directories(constants INTERFACE constants.h)