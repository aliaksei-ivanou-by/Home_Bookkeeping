include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(
    tests
    "test_Main.cpp"
    "test_Tag.cpp"
    "test_Payee.cpp"
    "test_Description.cpp"
    "test_Comment.cpp"
    "test_Category.cpp"
      "test_Currency.cpp" "test_Account.cpp")

target_link_libraries(tests
  PRIVATE
    constants enum logger sqlite
    Models DataAccess BusinessLogic
    gtest_main
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )