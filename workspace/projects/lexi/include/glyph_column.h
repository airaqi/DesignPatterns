#ifndef __GLYPH_COLUMN_H__
#define __GLYPH_COLUMN_H__ 

#include "glyph.h"
#include "glyph_composite.h"

class GlyphColumn : public GlyphComposite
{
    public:
        GlyphColumn(Glyph* parent = nullptr);
};

#endif /* ifndef __GLYPH_COLUMN_H__ */
