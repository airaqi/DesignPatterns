add_library(bridge
    window.cpp
    window_application.cpp
    view_composite.cpp
    view_rectangle.cpp
    view_string.cpp
    window_imp_x.cpp
    window_imp_xcb.cpp
    factory_window_system.cpp
    factory_window_system_x.cpp
    factory_window_system_xcb.cpp
)

find_package(X11 REQUIRED)

target_link_libraries(bridge common ${X11_LIBRARIES} ${X11_xcb_LIB})
