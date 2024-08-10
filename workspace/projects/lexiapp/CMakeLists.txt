add_subdirectory(src)

set(INCKUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(lexi PUBLIC ${INCKUDE_DIR})

