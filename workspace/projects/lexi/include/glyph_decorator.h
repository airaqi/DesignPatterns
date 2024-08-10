#ifndef __GLYPH_DECORATOR_H__
#define __GLYPH_DECORATOR_H__ 

#include "glyph.h"
#include "window.h"

class GlyphDecorator : public Glyph
{
    public: 
        GlyphDecorator(Glyph* component);

        virtual void draw(Window *) override;

    private:
        Glyph* _component;
};

#endif /* ifndef __GLYPH_DECORATOR_H__ */
