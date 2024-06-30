cmake_minimum_required(VERSION 3.11)

project(cpp_lib)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(pybind11)

pybind11_add_module(cpp_lib cpp_lib.cc)
