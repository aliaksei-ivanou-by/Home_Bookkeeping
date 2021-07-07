cmake_minimum_required(VERSION 3.8)

project(Home_Bookkeeping)

set(MAIN_EXE main.cpp)

add_executable(main ${MAIN_EXE})

# Add lib
include_directories(lib)
add_subdirectory(lib)
target_link_libraries(main constants)
target_link_libraries(main sqlite)
target_link_libraries(main logger)
target_link_libraries(main enum)

# Add Models
include_directories(0_Models)
add_subdirectory(0_Models)
target_link_libraries(main Model)
target_link_libraries(main Account)
target_link_libraries(main Currency)
target_link_libraries(main Category)
target_link_libraries(main Comment)
target_link_libraries(main Description)
target_link_libraries(main Payee)
target_link_libraries(main Tag)
target_link_libraries(main Time)
target_link_libraries(main Type)
target_link_libraries(main Status)
target_link_libraries(main Transaction)

# Add DataAccess
include_directories(1_DataAccess)
add_subdirectory(1_DataAccess)
target_link_libraries(main AccountRepository)
target_link_libraries(main CategoryRepository)
target_link_libraries(main CommentRepository)
target_link_libraries(main CurrencyRepository)
target_link_libraries(main DescriptionRepository)
target_link_libraries(main PayeeRepository)
target_link_libraries(main TagRepository)
target_link_libraries(main TransactionRepository)

# Add BusinessLogic
include_directories(2_BusinessLogic)
add_subdirectory(2_BusinessLogic)
target_link_libraries(main DatabaseManager)
target_link_libraries(main FinanceRepository)
