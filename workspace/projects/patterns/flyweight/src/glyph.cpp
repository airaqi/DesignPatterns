#include "glyph.hpp"
#include "glyph_context.hpp"
#include <format>
#include <ostream>

void Glyph::setFont(Font::Ptr font, int span, GlyphContext& ctxt) { ctxt.setFont(font, span); }

std::optional<Font::Ptr> Glyph::getFont(GlyphContext& ctxt) { return ctxt.getFont(); }

void Glyph::first(GlyphContext& ctxt) { ctxt.reset(); }
void Glyph::next(GlyphContext& ctxt) { ctxt.next(); }
void Glyph::prev(GlyphContext& ctxt) { ctxt.prev(); }
bool Glyph::is_done(GlyphContext& ctxt) { return ctxt.index() == size() ? true : false; }

bool Glyph::is_composite() { return false; }

std::string Glyph::to_string(std::string prefix)
{
    return std::format("{}{}", prefix, typeid(*this).name() );
}

bool Glyph::equal(Glyph& that) { return is_equal(that); }

bool Glyph::operator==(Glyph& that) { return equal(that); }
bool Glyph::operator!=(Glyph& that) { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, Glyph& that) { return out << that.to_string(); }

