cmake_minimum_required(VERSION 3.10)
 set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++")
project(matrix)

add_subdirectory(src)
add_subdirectory(allocator)
add_subdirectory(LinAlgebra)