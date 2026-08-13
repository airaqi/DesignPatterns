#include "glyph_row.hpp"
#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include <format>
#include <memory>
#include <string>

GlyphRow::Ptr GlyphRow::create() { return std::make_shared<GlyphRow>(); }

void GlyphRow::draw(Window& window, GlyphContext& ctxt)
{
    window.draw(*this, ctxt);
}

void GlyphRow::insert(Glyph::Ptr child, GlyphContext& ctxt)
{
    add(child);
    ctxt.insert(1);
    next(ctxt);
 }

Glyph& GlyphRow::current(GlyphContext& ctxt) { return get(ctxt.index()).current(ctxt); }

bool GlyphRow::is_equal(Glyph& that) 
{
    return (typeid(that) == typeid(GlyphRow) && GlyphComposite::is_equal(that));
}

std::string GlyphRow::to_string(std::string prefix)
{
    return std::format("\n{}[Row: {}]", prefix, GlyphComposite::to_string(prefix + prefix));
}
