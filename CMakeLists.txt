cmake_minimum_required(VERSION 3.4)
project(tests)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

add_library(main ${CMAKE_CURRENT_SOURCE_DIR}/main/main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/main)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB EXAMPLE_TEST_SOURCES tests/*.cpp)
  add_executable(check ${EXAMPLE_TEST_SOURCES})
  target_link_libraries(check main gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()

include(CPack.cmake)
