#ifndef __GLYPH_DECORATOR_BORDER_H__
#define __GLYPH_DECORATOR_BORDER_H__ 

#include "glyph.h"
#include "glyph_decorator.h"
#include "window.h"

class GlyphDecoratorBorder : public GlyphDecorator
{
    public:
        GlyphDecoratorBorder(Glyph* component);

        virtual void draw(Window *) override;
};

#endif /* ifndef __GLYPH_DECORATOR_BORDER_H__ */
