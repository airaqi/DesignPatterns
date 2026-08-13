#include "glyph_context.hpp"
#include <format>
#include <optional>
#include <string>

GlyphContext::GlyphContext(Font::Ptr defaultFont) : _index(0), _col(0), _row(0), _fonts(defaultFont), _defaultFont(defaultFont) {}

int GlyphContext::row()                     { return _row; }
int GlyphContext::col()                     { return _col; }
int GlyphContext::index()                   { return _index; }

void GlyphContext::next(int step)           { _index += step; }
void GlyphContext::nextCol(int step)        { _col += step; }
void GlyphContext::nextRow(int step)        { _row += step; }

void GlyphContext::prev(int step)           { _index -= step; }
void GlyphContext::prevCol(int step)        { _col -= step; }
void GlyphContext::prevRow(int step)        { _row -= step; }

void GlyphContext::reset()                  { _index = _col = _row = 0; }
void GlyphContext::restore(GlyphContext& ctxt) 
{
    reset();
    next(ctxt.index());
    nextCol(ctxt.col());
    nextCol(ctxt.row());
}

void GlyphContext::insert(int span)         { _fonts.insert(_index, span); }

std::optional<Font::Ptr> GlyphContext::getFont() 
{
    std::optional<Font::Ptr> font = _fonts.getValue(_index);
    if (font.has_value())
        return font;
    return std::optional<Font::Ptr>(_defaultFont);
}

void GlyphContext::setFont(Font::Ptr font, int span)
{
    _fonts.setValue(_index, span, font);
}

std::string GlyphContext::to_string(std::string prefix)
{
    return std::format("Context: [index: {}, row: {}, col: {}, size: {}, fonts: \n{} ]", 
            _index, _row, _col, _fonts.size(), _fonts.to_string("  "));
}
