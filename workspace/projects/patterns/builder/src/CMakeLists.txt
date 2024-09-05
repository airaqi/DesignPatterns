add_library(${LIBRARY_NAME}
    dummy.cpp
    maze_builder_standard.cpp
    maze_builder_counting.cpp
    maze_game_ext.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES} ${EXTRA_LINK_LIBS})
