add_library(${LIBRARY_NAME}
    dummy.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES})
