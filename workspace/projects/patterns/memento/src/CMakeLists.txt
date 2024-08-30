add_library(${LIBRARY_NAME}
    command_move.cpp
    command_create_rectangle.cpp
    command_connect.cpp
    graphic_line.cpp
    graphic_connect.cpp
    graphic_rectangle.cpp
    graphic_canvas.cpp
    constraint_solver.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES})
