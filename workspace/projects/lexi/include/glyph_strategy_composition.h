#ifndef __GLYPH_STRATEGY_COMPOSITION_H__
#define __GLYPH_STRATEGY_COMPOSITION_H__ 

#include "glyph.h"

class GlyphStrategyComposition : public Glyph
{
    public:
        GlyphStrategyComposition();
        
        virtual void insert(Glyph*, int);
};

#endif /* ifndef __GLYPH_STRATEGY_COMPOSITION_H__ */
