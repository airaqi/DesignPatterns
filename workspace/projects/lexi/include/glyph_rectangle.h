#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__ 

#include "coord.h"
#include "glyph_leaf.h"
#include "rect.h"
#include "window.h"

class GlyphRectangle : public GlyphLeaf
{
    public: 
        GlyphRectangle(Rect rect = Rect(), Glyph* parent = nullptr);
        GlyphRectangle(Coord x = 0, Coord y = 0, Coord w = 0, Coord h = 0, Glyph* parent = nullptr);

        virtual void draw(Window*);

        friend bool operator==(GlyphRectangle& lhs, GlyphRectangle& rhs);
        friend bool operator!=(GlyphRectangle& lhs, GlyphRectangle& rhs);
        
};

#endif /* ifndef __RECTANGLE_H__ */
