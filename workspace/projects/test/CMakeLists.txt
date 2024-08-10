add_subdirectory(src)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(test PUBLIC ${INCLUDE_DIR}) 


