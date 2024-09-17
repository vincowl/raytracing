cmake_minimum_required(VERSION 3.5.0)
project(
  Raytracing
  VERSION 0.1.0
  LANGUAGES C CXX)

add_library(LibFilewriter src/filewriter.cpp)

add_executable(Raytracing src/main.cpp)
target_link_libraries(Raytracing PUBLIC LibFilewriter)

include(CTest)
enable_testing()
