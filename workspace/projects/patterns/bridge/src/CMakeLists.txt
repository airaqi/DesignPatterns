add_library(bridge
    window.cpp
    window_application.cpp
    view_composite.cpp
    view_rectangle.cpp
    view_string.cpp
    x_window_imp.cpp
    factory_window_system.cpp
    x_factory_window_system.cpp
)

find_package(X11 REQUIRED)

target_link_libraries(bridge common ${X11_LIBRARIES})
