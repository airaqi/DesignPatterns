add_subdirectory(src)

add_executable(strategyapp main.cpp)   
target_link_libraries(strategyapp strategy)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(strategy PUBLIC ${INCLUDE_DIR})
target_include_directories(strategy INTERFACE ${INCLUDE_DIR})
