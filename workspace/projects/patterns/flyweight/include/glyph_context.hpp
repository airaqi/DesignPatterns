#ifndef __GLYPH_CONTEXT_H__
#define __GLYPH_CONTEXT_H__ 

#include "btree.hpp"
#include "font.hpp"
#include <optional>
#include <string>

class GlyphContext
{
    private:
        int _index;
        int _row;
        int _col;
        Btree<Font::Ptr> _fonts;
        Font::Ptr _defaultFont;

    public:
        GlyphContext(Font::Ptr defaultFont);

        int row();
        int col();
        int index();

        void next(int step = 1);
        void nextCol(int step = 1);
        void nextRow(int step = 1);

        void prev(int step = 1);
        void prevCol(int step = 1);
        void prevRow(int step = 1);

        void reset();
        void restore(GlyphContext&);

        void insert(int span);
        std::optional<Font::Ptr> getFont();
        void setFont(Font::Ptr font, int span);

        std::string to_string(std::string prefix="");

        bool operator==(GlyphContext& that);

};
#endif /* ifndef __GLYPH_CONTEXT_H__ */
