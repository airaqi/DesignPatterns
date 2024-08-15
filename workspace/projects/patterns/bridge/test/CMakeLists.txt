add_executable(test_bridge test_all.cpp)

find_package(doctest REQUIRED)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(test_decorator PUBLIC ${INCLUDE_DIR} ${SRC_DIR})

target_link_libraries(test_bridge doctest::doctest bridge)

add_test(NAME run_test_bridge COMMAND test_bridge)

