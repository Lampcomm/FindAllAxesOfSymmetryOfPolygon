cmake_minimum_required(VERSION 3.29)
project(SearchForAllAxesOfSymmetry)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp)

add_executable(SearchForAllAxesOfSymmetry ${SOURCES})
target_include_directories(SearchForAllAxesOfSymmetry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)