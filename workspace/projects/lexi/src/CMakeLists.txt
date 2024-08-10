add_library(lexi glyph.cpp glyph_composite.cpp glyph_leaf.cpp glyph_row.cpp glyph_column.cpp glyph_character.cpp glyph_rectangle.cpp)

target_link_libraries(lexi common)
