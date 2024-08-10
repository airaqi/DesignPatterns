#include "glyph_character.h"
#include "glyph.h"
#include "glyph_leaf.h"
#include "rect.h"
#include "window.h"
#include <string>

GlyphCharacter::GlyphCharacter(char ch, Coord x, Coord y, Coord w, Coord h, Glyph* parent) : GlyphLeaf(parent), _ch(ch) 
{
    rect(Rect(x, y, w, h));
}

void GlyphCharacter::draw(Window* w) 
{
   w->text(rect().left(), rect().bottom(), std::to_string(ch()));
}

/*bool GlyphCharacter::equals(Glyph* other) */
/*{*/
    /*std::cout << "GlyphCharacter::equals(Glyph)\n";*/
    /*return other->equals(this);*/
/*}*/

/*bool GlyphCharacter::equals(GlyphCharacter* other)*/
/*{*/
    /*std::cout << "GlyphCharacter::equals(GlyphCharacter)\n";*/
    /*return (ch() == other->ch()  && rect() == other->rect());*/
/*}*/

bool operator==(GlyphCharacter& lhs, GlyphCharacter& rhs)
{
    return (lhs.ch() == rhs.ch() && lhs.rect() == rhs.rect());
}

bool operator!=(GlyphCharacter& lhs, GlyphCharacter& rhs)
{
    return (lhs.ch() != rhs.ch() || lhs.rect() != rhs.rect());
}


