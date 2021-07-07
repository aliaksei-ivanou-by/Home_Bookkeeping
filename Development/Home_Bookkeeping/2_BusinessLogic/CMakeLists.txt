cmake_minimum_required(VERSION 3.8)

project(2_BusinessLogic)

set(SOURCE_LIB_2_BusinessLogic_DatabaseManager "DatabaseManager.cpp")
add_library(DatabaseManager STATIC ${SOURCE_LIB_2_BusinessLogic_DatabaseManager})

set(SOURCE_LIB_2_BusinessLogic_FinanceRepository "FinanceRepository.cpp")
add_library(FinanceRepository STATIC ${SOURCE_LIB_2_BusinessLogic_FinanceRepository})
