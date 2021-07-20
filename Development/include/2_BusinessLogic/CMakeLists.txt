cmake_minimum_required(VERSION 3.8)

project(2_BusinessLogic)

add_library(
  BusinessLogic
  STATIC
  "FinanceRepository.cpp" "FinanceRepository.h"
)
