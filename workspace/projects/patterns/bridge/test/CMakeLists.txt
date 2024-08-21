set(TEST_LIBRARY "test_${LIBRARY_NAME}")
SET(RUN_TEST "run_${TEST_LIBRARY}")

add_executable(${TEST_LIBRARY} test_all.cpp)

find_package(${TEST_PKG} REQUIRED)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${TEST_LIBRARY} PUBLIC ${INCLUDE_DIR} ${SRC_DIR})

target_link_libraries(${TEST_LIBRARY} ${TEST_FW} ${LIBRARY_NAME})

add_test(NAME ${RUN_TEST} COMMAND ${TEST_LIBRARY})

