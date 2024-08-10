#ifndef __GLYPH_STRATEGY_COMPOSITOR_ARRAY_H__
#define __GLYPH_STRATEGY_COMPOSITOR_ARRAY_H__ 

#include "glyph_strategy_compositor.h"

class GlyphStrategyCompositorArray : public GlyphStrategyCompositor
{
    public:
        GlyphStrategyCompositorArray();

        virtual void compose() override;
};

#endif /* ifndef __GLYPH_STRATEGY_COMPOSITOR_ARRAY_H__ */ 
