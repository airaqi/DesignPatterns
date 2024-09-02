add_library(${LIBRARY_NAME} 
    equipment.cpp 
    composite_equipment.cpp 
    leaf_equipment.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES})

