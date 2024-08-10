#include "glyph_rectangle.h"
#include "glyph.h"
#include "glyph_leaf.h"
#include "rect.h"

GlyphRectangle::GlyphRectangle(Rect rec, Glyph* parent) : GlyphLeaf(parent) 
{
    rect(rec);
}

GlyphRectangle::GlyphRectangle(Coord x, Coord y, Coord w, Coord h, Glyph* parent) : GlyphRectangle(Rect(x, y, w, h), parent) {}

void GlyphRectangle::draw(Window* w)
{
    w->rectangle(rect().left(), rect().top(), rect().right(), rect().bottom());
}


bool operator==(GlyphRectangle& lhs, GlyphRectangle& rhs)
{
    return (lhs.rect() == rhs.rect());
}

bool operator!=(GlyphRectangle& lhs, GlyphRectangle& rhs)
{
    return (lhs.rect() != rhs.rect());
}

// create function to generate prime numbers

