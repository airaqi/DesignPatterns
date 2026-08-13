#include "glyph_leaf.hpp"
#include "glyph_context.hpp"
#include <vector>

int GlyphLeaf::size() { return 1; }
void GlyphLeaf::insert(Glyph::Ptr child, GlyphContext& ctxt) {}
Glyph& GlyphLeaf::current(GlyphContext&) {return *this; }
std::vector<Glyph::Ptr>& GlyphLeaf::children() { return _empty; }
