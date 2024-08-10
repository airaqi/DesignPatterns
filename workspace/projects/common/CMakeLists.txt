#add_library(common INTERFACE)

message("common current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(src)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(common PUBLIC "${INCLUDE_DIR}")
target_include_directories(common INTERFACE ${INCLUDE_DIR})
#target_include_directories(common INTERFACE "${INCLUDE_DIR}")
