add_library(${LIBRARY_NAME}
    # dummy.cpp
    font.cpp
    glyph.cpp
    glyph_composite.cpp
    glyph_leaf.cpp
    glyph_context.cpp
    glyph_factory.cpp
    glyph_document.cpp
    glyph_column.cpp
    glyph_row.cpp
    glyph_character.cpp
    window_console.cpp
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES} ${EXTRA_LINK_LIBS})
