# cmake_minimum_required(VERSION 3.5)

project(patterns VERSION 1.0)

# c++ standard
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_compile_options(-fPIC)
#add_compile_options(-g)

include(CTest)
include(FetchContent)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_Declare(
    plog
    GIT_REPOSITORY https://github.com/SergiusTheBest/plog
    GIT_TAG        1.1.10
    GIT_SHALLOW    true
)
FetchContent_MakeAvailable(plog) # Downloads and adds plog to your CMake project

#set(TEST_PKG doctest)
#set(TEST_FW "doctest::doctest")

#set(X11_PKG "X11")
#set(COMMON_LIB "common")

add_subdirectory(patterns)
add_subdirectory(lexi)
add_subdirectory(common)

