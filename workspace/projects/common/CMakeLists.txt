add_subdirectory(test)

set(TARGET_SOURCES currency.cpp watt.cpp point.cpp rect.cpp)
list(TRANSFORM TARGET_SOURCES PREPEND "src/")

add_library(common ${TARGET_SOURCES})

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(common PUBLIC "${INCLUDE_DIR}")
target_include_directories(common INTERFACE ${INCLUDE_DIR})
