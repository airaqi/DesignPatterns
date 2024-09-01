cmake_minimum_required(VERSION 3.30)

set(PATTERN_NAME prototype)
set(EXTRA_LINK_LIBS abstract_factory)

set(LIBRARY_NAME ${PATTERN_NAME})
set(EXEC_NAME "${PATTERN_NAME}_app")

project(${EXEC_NAME} VERSION 1.0)

add_subdirectory(src)
add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)
add_test(run_memtest_${PATTERN_NAME} ${EXEC_NAME})

target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME} ${EXTRA_LINK_LIBS})

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${LIBRARY_NAME} PUBLIC "${INCLUDE_DIR}" ${SRC_DIR})
target_include_directories(${LIBRARY_NAME} INTERFACE "${INCLUDE_DIR}")

