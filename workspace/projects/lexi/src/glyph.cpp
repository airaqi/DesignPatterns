#include "glyph.h"

Glyph::Glyph(Glyph* parent) : _parent(parent) {}

Glyph* Glyph::parent() { return _parent; }
void Glyph::parent(Glyph* parent) { _parent = parent; }

bool operator==(Glyph& lhs, Glyph& rhs)
{
    return lhs.equals(&rhs);
}

bool operator!=(Glyph& lhs, Glyph& rhs)
{
    return !lhs.equals(&rhs);
}
