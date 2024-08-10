find_package(doctest REQUIRED)

add_executable(test_decorator test_all.cpp)
target_link_libraries(test_decorator doctest::doctest decorator)
