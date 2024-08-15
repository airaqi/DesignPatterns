add_executable(test_common test_all.cpp)

find_package(doctest REQUIRED)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_include_directories(test_common PUBLIC ${INCLUDE_DIR} ${SRC_DIR}) 
target_link_libraries(test_common doctest::doctest common)

add_test(NAME run_test_common COMMAND test_common)

