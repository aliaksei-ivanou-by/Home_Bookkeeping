cmake_minimum_required(VERSION 3.8)

project(sqlite)

add_library(sqlite STATIC sqlite3.c sqlite3.h sqlite3ext.h)
