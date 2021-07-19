cmake_minimum_required (VERSION 3.8)

project ("Home_Bookkeeping")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

set(BASEPATH "${CMAKE_SOURCE_DIR}")
include_directories("${BASEPATH}")
include_directories("${BASEPATH}/lib/FLTK/FLTK")
include_directories("${BASEPATH}/lib/FLTK/FLTK_lib_Release")
include_directories("${BASEPATH}/lib/FLTK/FLTK_lib_Debug")

add_subdirectory(include)
add_subdirectory(test)
add_subdirectory(lib)

add_executable(main main.cpp)

target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltkd)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_formsd)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_gld)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_imagesd)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_jpegd)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_pngd)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Debug/fltk_zd)

target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_forms)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_gl)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_images)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_jpeg)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_png)
target_link_libraries(main -L/lib/FLTK/FLTK_lib_Release/fltk_z)

target_link_libraries(main fltk)
target_link_libraries(main fltk_forms)
target_link_libraries(main fltk_gl)
target_link_libraries(main fltk_images)
target_link_libraries(main fltk_jpeg)
target_link_libraries(main fltk_png)
target_link_libraries(main fltk_z)

target_link_libraries(main constants)
target_link_libraries(main sqlite)
target_link_libraries(main logger)
target_link_libraries(main enum)
target_link_libraries(main graph)

target_link_libraries(main Models)
target_link_libraries(main DataAccess)
target_link_libraries(main BusinessLogic)
target_link_libraries(main GUI)

enable_testing()
