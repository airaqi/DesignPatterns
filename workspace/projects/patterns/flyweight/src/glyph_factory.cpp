#include "glyph_factory.hpp"
#include "font.hpp"
#include "glyph_character.hpp"
#include "glyph_column.hpp"
#include <format>
#include <map>
#include <numeric>
#include <string>
#include <utility>

GlyphFactory GlyphFactory::_instance;

GlyphFactory& GlyphFactory::get() { return _instance; }

std::map<char, GlyphCharacter::Ptr> GlyphFactory::getCharPool() { return _charPool; }
std::map<std::string, Font::Ptr> GlyphFactory::getFontPool() { return _fontPool; }

GlyphDocument::Ptr GlyphFactory::getDocument() { return GlyphDocument::create(); }
GlyphColumn::Ptr GlyphFactory::getColumn() { return GlyphColumn::create(); }
GlyphRow::Ptr GlyphFactory::getRow() { return GlyphRow::create(); }

GlyphCharacter::Ptr GlyphFactory::getCharacter(char character) 
{ 
    if (!_charPool.contains(character))
        _charPool.insert_or_assign(character, GlyphCharacter::create(character));

    _totalObjectsCreated++;
    return _charPool.at(character);
}

Font::Ptr GlyphFactory::getFont(std::string name, int size) { return getFont(name, size, Font::Color::Value::RESET); }

Font::Ptr GlyphFactory::getFont(std::string name, int size, Font::Color color)
{
    std::string fontname = Font::createFullname(name, size, color);
    if (!_fontPool.contains(fontname))
        _fontPool.insert_or_assign(fontname, Font::create(name, size, color));
    return _fontPool.at(fontname);


}

int GlyphFactory::getTotalObjectsCreated() { return _totalObjectsCreated; }

std::string GlyphFactory::printCharPool()
{
    return std::format("{}", std::accumulate(_charPool.begin(), _charPool.end(), std::string(""), 
                [](std::string acc, std::pair<char, GlyphCharacter::Ptr> entry) 
                { return std::format("{}{}({}->{})", acc, (acc.empty() ? "" : ", "), entry.first, entry.second->to_string()); }));
}

std::string GlyphFactory::printFontPool() 
{
    return std::format("{}", std::accumulate(_fontPool.begin(), _fontPool.end(), std::string(""),
                [](std::string acc, std::pair<std::string, Font::Ptr> entry)
                { return std::format("{}{}({} -> {})", acc, (acc.empty() ? "" : "\n"), entry.first, entry.second->to_string("name")); }));
}
