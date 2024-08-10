#ifndef __GLYPH_STRATEGY_COMPOSITOR_H__
#define __GLYPH_STRATEGY_COMPOSITOR_H__ 

#include "glyph_strategy_composition.h"

class GlyphStrategyCompositor
{
    public:
        GlyphStrategyCompositor();

        virtual void compose();
        virtual void setComposition(GlyphStrategyComposition* composition);

    private:
        GlyphStrategyComposition* _composition;
};

#endif /* ifndef __GLYPH_STRATEGY_COMPOSITOR_H__ */
