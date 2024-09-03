add_library(${LIBRARY_NAME}
    dummy.cpp
    equipment_visitor_pricing.cpp
    equipment_visitor_inventory.cpp
    equipment_inventory.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES} ${EXTRA_LINK_LIBS})
