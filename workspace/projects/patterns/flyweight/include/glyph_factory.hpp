#ifndef __GLYPH_FACTORY_H__
#define __GLYPH_FACTORY_H__ 

#include "glyph_character.hpp"
#include "glyph_column.hpp"
#include "glyph_document.hpp"
#include "glyph_row.hpp"
#include <map>
#include <string>

class GlyphFactory
{
    private:
        static GlyphFactory _instance;

        std::map<char, GlyphCharacter::Ptr> _charPool;
        std::map<std::string, Font::Ptr> _fontPool;
        int _totalObjectsCreated;

    protected:
        GlyphFactory() = default;

    public:
        static GlyphFactory& get();

        std::map<char, GlyphCharacter::Ptr> getCharPool();
        std::map<std::string, Font::Ptr> getFontPool();

        GlyphCharacter::Ptr getCharacter(char character);
        GlyphDocument::Ptr getDocument();
        GlyphColumn::Ptr getColumn();
        GlyphRow::Ptr getRow();
        Font::Ptr getFont(std::string name, int size);
        Font::Ptr getFont(std::string name, int size, Font::Color color);

        int getTotalObjectsCreated();

        std::string printCharPool();
        std::string printFontPool();

};

#endif /* ifndef __GLYPH_FACTORY_H__ */
