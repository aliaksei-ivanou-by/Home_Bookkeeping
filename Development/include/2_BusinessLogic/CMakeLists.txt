cmake_minimum_required(VERSION 3.8)

project(2_BusinessLogic)

add_library(
  BusinessLogic
  STATIC
  "DatabaseManager.cpp" "DatabaseManager.h"
  "FinanceRepository.cpp" "FinanceRepository.h"
)
