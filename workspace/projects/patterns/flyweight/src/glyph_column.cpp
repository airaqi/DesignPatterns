#include "glyph_column.hpp"
#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include "glyph_factory.hpp"
#include "window.hpp"
#include <format>
#include <memory>
#include <string>

GlyphColumn::GlyphColumn() : _CR(GlyphFactory::get().getCharacter('\n'))
{ 
    add(0, std::static_pointer_cast<Glyph>(GlyphFactory::get().getRow())); 
}

GlyphColumn::Ptr GlyphColumn::create() { return std::make_shared<GlyphColumn>(); }

void GlyphColumn::draw(Window& window, GlyphContext& ctxt)
{
    window.draw(*this, ctxt);
}

void GlyphColumn::insert(Glyph::Ptr child, GlyphContext& ctxt)
{
    if (typeid(*child) == typeid(GlyphRow))
        add(child);
    else if (typeid(*child) == typeid(GlyphCharacter))
    {
        get(ctxt.row()).insert(child, ctxt);
        if (*child == *_CR) 
        {
            add(std::static_pointer_cast<Glyph>(GlyphFactory::get().getRow()));
            ctxt.nextRow();
        }
    }
}

Glyph& GlyphColumn::current(GlyphContext& ctxt) 
{
    return get(ctxt.row()).current(ctxt);
}

bool GlyphColumn::is_equal(Glyph& that) 
{
    return (typeid(that) == typeid(GlyphColumn) && GlyphComposite::is_equal(that));
}

std::string GlyphColumn::to_string(std::string prefix)
{
    return std::format("\n{}[Col: {}]", prefix, GlyphComposite::to_string(prefix + prefix));
}
