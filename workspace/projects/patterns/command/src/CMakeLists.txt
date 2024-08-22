add_library(${LIBRARY_NAME}
    application.cpp
    command_macro.cpp
    command_open.cpp
    command_paste.cpp
    document.cpp
    application_menu.cpp
    application_menu_item.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES})
