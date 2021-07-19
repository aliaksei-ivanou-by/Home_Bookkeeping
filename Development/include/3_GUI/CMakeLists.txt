cmake_minimum_required(VERSION 3.8)

project(3_GUI)

add_library(
  GUI
  STATIC
  Window_AddAccount.cpp Window_AddAccount.h
  Window_AddTransactionExpense.cpp Window_AddTransactionExpense.h
  Window_AddTransactionIncome.cpp Window_AddTransactionIncome.h
  Window_AddTransactionTransfer.cpp Window_AddTransactionTransfer.h
  Window_Main.cpp Window_Main.h
)
