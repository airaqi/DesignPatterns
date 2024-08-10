#ifndef __GLYPH_ROW_H__
#define __GLYPH_ROW_H__ 

#include "glyph.h"
#include "glyph_composite.h"
class GlyphRow : virtual public GlyphComposite
{
    public:
        GlyphRow(Glyph* parent = nullptr);


};
#endif /* ifndef __GLYPH_ROW_H__ */
