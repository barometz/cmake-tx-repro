cmake_minimum_required(VERSION 3.14)
project(cmake-tx-bug)

add_executable(cmake-tx-bug tests.cpp)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
  )
FetchContent_MakeAvailable(googletest)

target_link_libraries(cmake-tx-bug PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(cmake-tx-bug)
