#ifndef __CHARACTER_H__
#define __CHARACTER_H__ 

#include "glyph.h"
#include "glyph_leaf.h"
#include "window.h"

class GlyphCharacter : virtual public GlyphLeaf 
{
    public: 
        GlyphCharacter(char ch = 0, Coord x = 0, Coord y = 0, Coord w = 10, Coord h = 10, Glyph* parent = nullptr);

        char ch() const { return _ch; }     void ch(char ch) { _ch = ch; }

        virtual void draw(Window*);

/*        virtual bool equals(Glyph*);*/
        /*virtual bool equals(GlyphCharacter*);*/

        friend bool operator==(GlyphCharacter& lhs, GlyphCharacter& rhs);
        friend bool operator!=(GlyphCharacter& lhs, GlyphCharacter& rhs);

    private:
        char _ch;
};

#endif /* ifndef __CHARACTER_H__ */
