add_library(composite equipment.cpp composite_equipment.cpp leaf_equipment.cpp)
message("libequipment current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(composite common)

