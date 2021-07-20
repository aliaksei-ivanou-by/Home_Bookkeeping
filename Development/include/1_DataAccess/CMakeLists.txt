cmake_minimum_required(VERSION 3.8)

project(1_DataAccess)

add_library(
  DataAccess
  STATIC
  "AccountRepository.cpp" "AccountRepository.h"
  "CategoryRepository.cpp" "CategoryRepository.h"
  "CommentRepository.cpp" "CommentRepository.h"
  "CurrencyRepository.cpp" "CurrencyRepository.h"
  "DescriptionRepository.cpp" "DescriptionRepository.h"
  "PayeeRepository.cpp" "PayeeRepository.h"
  "TagRepository.cpp" "TagRepository.h"
  "TransactionRepository.cpp" "TransactionRepository.h"
  "DatabaseManager.cpp" "DatabaseManager.h"
  "AccountDatabase.h" "AccountDatabase.cpp"
  "CommentDatabase.cpp" "CommentDatabase.h"
  "CurrencyDatabase.cpp" "CurrencyDatabase.h"
  "DescriptionDatabase.cpp" "DescriptionDatabase.h"
   "PayeeDatabase.cpp" "TagDatabase.cpp" "TagDatabase.h" "TransactionDatabase.cpp")
