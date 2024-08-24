cmake_minimum_required(VERSION 3.30)

project(command_app VERSION 1.0)
set(LIBRARY_NAME command)

add_subdirectory(src)
add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${LIBRARY_NAME} PUBLIC "${INCLUDE_DIR}" ${SRC_DIR})
target_include_directories(${LIBRARY_NAME} INTERFACE "${INCLUDE_DIR}")

