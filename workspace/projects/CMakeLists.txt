cmake_minimum_required(VERSION 3.30)

project(patterns VERSION 1.0)

# c++ standard
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_compile_options(-fPIC)
#add_compile_options(-g)

include(CTest)

#set(TEST_PKG doctest)
#set(TEST_FW "doctest::doctest")

#set(X11_PKG "X11")
#set(COMMON_LIB "common")

add_subdirectory(patterns)
add_subdirectory(lexi)
add_subdirectory(common)

