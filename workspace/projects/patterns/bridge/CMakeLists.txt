add_subdirectory(src)

add_executable(bridge_app main.cpp)

target_link_libraries(bridge_app bridge)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(bridge PUBLIC "${INCLUDE_DIR}")
target_include_directories(bridge INTERFACE "${INCLUDE_DIR}")

