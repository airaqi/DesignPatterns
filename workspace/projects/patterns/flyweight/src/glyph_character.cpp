#include "glyph_character.hpp"
#include "glyph.hpp"
#include "glyph_context.hpp"
#include "window.hpp"
#include <format>
#include <memory>
#include <string>

GlyphCharacter::GlyphCharacter(char c) : _character(c) {}

GlyphCharacter::Ptr GlyphCharacter::create(char c) { return std::make_shared<GlyphCharacter>(c); }

char GlyphCharacter::character() { return _character; }

void GlyphCharacter::draw(Window& window, GlyphContext& ctxt)
{
    window.draw(*this, ctxt);
}

bool GlyphCharacter::is_equal(Glyph& that) 
{
    if (GlyphCharacter* other = dynamic_cast<GlyphCharacter*>(&that))
        return (character() == other->character());
    return false;
}

std::string GlyphCharacter::to_string(std::string prefix)
{
    return to_string(false);
}

std::string GlyphCharacter::to_string(bool print, std::string prefix)
{
    if (print) return std::format("{}", character());

    std::string ch;

    switch (character()) {
        case ' ':
            {
            ch = "🞃";
            break;
            }
        case '\n':
            {
            ch = "↲";
            break;
            }
        case '\t':
            {
                ch = "↦";
                break;
            }
        default:
            ch = std::format("{}", character());
            
    };
    return std::format("{}", ch);
}
