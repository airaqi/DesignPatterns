add_subdirectory(src)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(singleton PUBLIC ${INCLUDE_DIR})
target_include_directories(singleton INTERFACE ${INCLUDE_DIR})
