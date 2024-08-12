add_subdirectory(src)

add_executable(abstract_factory_app main.cpp)

target_link_libraries(abstract_factory_app abstract_factory)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(abstract_factory PUBLIC "${INCLUDE_DIR}")
target_include_directories(abstract_factory INTERFACE "${INCLUDE_DIR}")

