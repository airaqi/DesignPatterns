find_package(doctest REQUIRED)
add_executable(test test_all.cpp)

target_link_libraries(test doctest::doctest common)
