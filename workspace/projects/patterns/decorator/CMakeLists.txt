add_subdirectory(src)
add_subdirectory(test)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(decorator PUBLIC ${INCLUDE_DIR})
target_include_directories(decorator INTERFACE ${INCLUDE_DIR})
