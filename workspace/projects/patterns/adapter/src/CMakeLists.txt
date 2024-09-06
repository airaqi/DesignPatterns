add_library(${LIBRARY_NAME}
    shape_text.cpp
    shape_text_object.cpp
    manipulator_text.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES} ${EXTRA_LINK_LIBS})
