#ifndef __WINDOW_H__
#define __WINDOW_H__ 

// #include "glyph_character.hpp"
// #include "glyph_column.hpp"
#include "glyph_context.hpp"
// #include "glyph_document.hpp"
// #include "glyph_row.hpp"

class GlyphDocument;
class GlyphColumn;
class GlyphRow;
class GlyphCharacter;

class Window
{
    public:
        virtual void draw(GlyphDocument& glyph, GlyphContext& ctxt) = 0;
        virtual void draw(GlyphColumn& glyph, GlyphContext& ctxt) = 0;
        virtual void draw(GlyphRow& glyph, GlyphContext& ctxt) = 0;
        virtual void draw(GlyphCharacter& glyph, GlyphContext& ctxt) = 0;

};

#endif /* ifndef __WINDOW_H__ */
