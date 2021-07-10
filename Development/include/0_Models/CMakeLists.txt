cmake_minimum_required(VERSION 3.8)

project(0_Models)

add_library(
  Models
  STATIC
  "Model.cpp" "Model.h"
  "Account.cpp" "Account.h"
  "Category.cpp" "Category.h"
  "Comment.cpp" "Comment.h"
  "Currency.cpp" "Currency.h"
  "Description.cpp" "Description.h"
  "Payee.cpp" "Payee.h"
  "Status.cpp" "Status.h"
  "Tag.cpp" "Tag.h"
  "TimeDate.cpp" "TimeDate.h"
  "Type.cpp" "Type.h"
  "Transaction.cpp" "Transaction.h"
  )
