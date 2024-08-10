add_subdirectory(src)
add_subdirectory(test)

set(INCKUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(lexi PUBLIC ${INCKUDE_DIR})
target_include_directories(lexi INTERFACE ${INCKUDE_DIR})

