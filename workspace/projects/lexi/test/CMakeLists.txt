find_package(doctest REQUIRED)
add_executable(test_lexi test_all.cpp)

target_link_libraries(test_lexi doctest::doctest lexi)
add_test(NAME run_test_lexi COMMAND test_lexi)

