#ifndef __WINDOW_CONSOLE_H__
#define __WINDOW_CONSOLE_H__ 

#include "glyph_context.hpp"
#include "window.hpp"

class ConsoleWindow : public Window
{
    virtual void draw(GlyphDocument& glyph, GlyphContext& ctxt);
    virtual void draw(GlyphColumn& glyph, GlyphContext& cxt);
    virtual void draw(GlyphRow& glyph, GlyphContext& ctxt);
    virtual void draw(GlyphCharacter& glyph, GlyphContext& ctxt);
};

#endif /* ifndef __WINDOW_CONSOLE_H__ */
