cmake_minimum_required(VERSION 3.30)

project(composite VERSION 1.0)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fPIC)
add_compile_options(-g)

include(CTest)

set(TEST_PKG doctest)
set(TEST_FW "doctest::doctest")

set(X11_PKG "X11")
set(COMMON_LIB "common")

add_subdirectory(patterns)
add_subdirectory(lexi)
add_subdirectory(common)

