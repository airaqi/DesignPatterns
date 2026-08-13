#include "glyph_document.hpp"
#include "glyph_column.hpp"
#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include "glyph_factory.hpp"
#include <format>
#include <memory>
#include <string>

GlyphDocument::GlyphDocument() 
{
    add(std::static_pointer_cast<Glyph>(GlyphFactory::get().getColumn()));
}

GlyphDocument::Ptr GlyphDocument::create() { return std::make_shared<GlyphDocument>(); }

void GlyphDocument::draw(Window& window, GlyphContext& ctxt) { window.draw(*this, ctxt); }

void GlyphDocument::insert(Glyph::Ptr child, GlyphContext& ctxt)
{
    if (typeid(*child) == typeid(GlyphColumn))
        add(child);
    else
        get(ctxt.col()).insert(child, ctxt);
}

Glyph& GlyphDocument::current(GlyphContext& ctxt) { return get(ctxt.col()).current(ctxt); }

bool GlyphDocument::is_equal(Glyph& that) 
{
    return (typeid(*this) == typeid(that) && GlyphComposite::is_equal(that));
}

std::string GlyphDocument::to_string(std::string prefix) 
{
    return std::format("[Doc: {}]", GlyphComposite::to_string(prefix));
}
