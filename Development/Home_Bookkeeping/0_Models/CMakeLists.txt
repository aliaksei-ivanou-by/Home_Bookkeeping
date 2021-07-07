cmake_minimum_required(VERSION 3.8)

project(0_Models)

set(SOURCE_LIB_0_Model_Model "Model.cpp")
add_library(Model STATIC ${SOURCE_LIB_0_Model_Model})

set(SOURCE_LIB_0_Model_Account "Account.cpp")
add_library(Account STATIC ${SOURCE_LIB_0_Model_Account})

set(SOURCE_LIB_0_Model_Currency "Currency.cpp")
add_library(Currency STATIC ${SOURCE_LIB_0_Model_Currency})

set(SOURCE_LIB_0_Model_Category "Category.cpp")

add_library(Category STATIC ${SOURCE_LIB_0_Model_Category})
set(SOURCE_LIB_0_Model_Comment "Comment.cpp")

add_library(Comment STATIC ${SOURCE_LIB_0_Model_Comment})

set(SOURCE_LIB_0_Model_Description "Description.cpp")
add_library(Description STATIC ${SOURCE_LIB_0_Model_Description})

set(SOURCE_LIB_0_Model_Payee "Payee.cpp")
add_library(Payee STATIC ${SOURCE_LIB_0_Model_Payee})

set(SOURCE_LIB_0_Model_Tag "Tag.cpp")
add_library(Tag STATIC ${SOURCE_LIB_0_Model_Tag})

set(SOURCE_LIB_0_Model_Time "TimeDate.cpp")
add_library(Time STATIC ${SOURCE_LIB_0_Model_Time})

set(SOURCE_LIB_0_Model_Type "Type.cpp")
add_library(Type STATIC ${SOURCE_LIB_0_Model_Type})

set(SOURCE_LIB_0_Model_Status "Status.cpp")
add_library(Status STATIC ${SOURCE_LIB_0_Model_Status})

set(SOURCE_LIB_0_Model_Transaction "Transaction.cpp")
add_library(Transaction STATIC ${SOURCE_LIB_0_Model_Transaction})
