cmake_minimum_required(VERSION 3.8)

project(1_DataAccess)

set(SOURCE_LIB_1_DataAccess_AccountRepository "AccountRepository.cpp")
add_library(AccountRepository STATIC ${SOURCE_LIB_1_DataAccess_AccountRepository})

set(SOURCE_LIB_1_DataAccess_CategoryRepository "CategoryRepository.cpp")
add_library(CategoryRepository STATIC ${SOURCE_LIB_1_DataAccess_CategoryRepository})

set(SOURCE_LIB_1_DataAccess_CommentRepository "CommentRepository.cpp")
add_library(CommentRepository STATIC ${SOURCE_LIB_1_DataAccess_CommentRepository})

set(SOURCE_LIB_1_DataAccess_CurrencyRepository "CurrencyRepository.cpp")
add_library(CurrencyRepository STATIC ${SOURCE_LIB_1_DataAccess_CurrencyRepository})

set(SOURCE_LIB_1_DataAccess_DescriptionRepository "DescriptionRepository.cpp")
add_library(DescriptionRepository STATIC ${SOURCE_LIB_1_DataAccess_DescriptionRepository})

set(SOURCE_LIB_1_DataAccess_PayeeRepository "PayeeRepository.cpp")
add_library(PayeeRepository STATIC ${SOURCE_LIB_1_DataAccess_PayeeRepository})

set(SOURCE_LIB_1_DataAccess_TagRepository "TagRepository.cpp")
add_library(TagRepository STATIC ${SOURCE_LIB_1_DataAccess_TagRepository})

set(SOURCE_LIB_1_DataAccess_TransactionRepository "TransactionRepository.cpp")
add_library(TransactionRepository STATIC ${SOURCE_LIB_1_DataAccess_TransactionRepository})
