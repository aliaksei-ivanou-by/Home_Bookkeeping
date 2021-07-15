cmake_minimum_required (VERSION 3.8)

project ("Home_Bookkeeping")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

set(BASEPATH "${CMAKE_SOURCE_DIR}")
include_directories("${BASEPATH}")

add_subdirectory(include)
add_subdirectory(test)
add_subdirectory(lib)

add_executable(main main.cpp)

target_link_libraries(main constants)
target_link_libraries(main sqlite)
target_link_libraries(main logger)
target_link_libraries(main enum)

target_link_libraries(main Models)
target_link_libraries(main DataAccess)
target_link_libraries(main BusinessLogic)

enable_testing()
