#include "window_console.hpp"
#include "glyph.hpp"
#include "glyph_character.hpp"
#include "glyph_column.hpp"
#include "glyph_context.hpp"
#include "glyph_document.hpp"
#include "glyph_row.hpp"
#include <algorithm>
#include <iostream>
#include <optional>
#include <sstream>

void ConsoleWindow::draw(GlyphDocument& glyph, GlyphContext& ctxt)
{
    GlyphContext temp(ctxt);

    glyph.first(ctxt);
    Font::Color def = Font::Color::Value::RESET;
    std::for_each(glyph.children().begin(), glyph.children().end(), 
            [this, &ctxt](Glyph::Ptr child) { child->draw(*this, ctxt); ctxt.nextCol(); });
    // std::cout << def.to_code();

    // restore context
    ctxt.restore(temp);
}

void ConsoleWindow::draw(GlyphColumn& glyph, GlyphContext& ctxt) 
{
    std::for_each(glyph.children().begin(), glyph.children().end(), 
            [this, &ctxt](Glyph::Ptr child) { child->draw(*this, ctxt); ctxt.nextRow(); });
}

void ConsoleWindow::draw(GlyphRow& glyph, GlyphContext& ctxt) 
{
    std::for_each(glyph.children().begin(), glyph.children().end(), 
            [this, &ctxt](Glyph::Ptr child) { child->draw(*this, ctxt); });
}

void ConsoleWindow::draw(GlyphCharacter& glyph, GlyphContext& ctxt)
{
    std::stringstream out;
    std::optional<Font::Ptr> font = ctxt.getFont();
    if(font.has_value()) out << font.value()->format(glyph.character());
    else out << glyph.character();
    glyph.next(ctxt);
    std::cout << out.str();
    // std::cout << font.value()->reset().to_code();
}
