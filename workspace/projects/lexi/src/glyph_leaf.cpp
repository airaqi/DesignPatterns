#include "glyph_leaf.h"
#include "glyph.h"
#include "iterator.h"
#include "list_iterator.h"
#include "point.h"
#include <stdexcept>

GlyphLeaf::GlyphLeaf(Glyph* parent) : Glyph(parent) {}

bool GlyphLeaf::isLeaf() { return true; }
bool GlyphLeaf::isComposite() { return false; }

bool GlyphLeaf::intersects(const Point& p)
{
    return rect().contains(p);
}

Iterator<Glyph*>* GlyphLeaf::iterator() { return new NullIterator<Glyph*>(); }

Rect GlyphLeaf::rect() { return _rect; }
void GlyphLeaf::rect(Rect rect) { _rect = rect; }

bool GlyphLeaf::equals(Glyph* other) { return false; }

void GlyphLeaf::bounds(Rect& bound) 
{
    bound = rect();
}

// throw exception for any composite methods.
void GlyphLeaf::append(Glyph* glyph)            { throw std::runtime_error(ERR_LEAF_CHILDREN); }
void GlyphLeaf::insert(Glyph* glyph, int index) { throw std::runtime_error(ERR_LEAF_CHILDREN); }
void GlyphLeaf::remove(Glyph*)                  { throw std::runtime_error(ERR_LEAF_CHILDREN); }
long GlyphLeaf::count() const                   { throw std::runtime_error(ERR_LEAF_CHILDREN); }
Glyph* GlyphLeaf::child(int index)              { throw std::runtime_error(ERR_LEAF_CHILDREN); }
