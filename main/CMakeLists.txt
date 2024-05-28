cmake_minimum_required(VERSION 3.4)
project(main)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(decorator ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

include(../CPack.cmake)
