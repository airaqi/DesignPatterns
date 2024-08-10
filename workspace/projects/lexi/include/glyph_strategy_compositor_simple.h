#ifndef __GLYPH_STRATEGY_COMPOSITOR_SIMPLE_H__
#define __GLYPH_STRATEGY_COMPOSITOR_SIMPLE_H__

#include "glyph_strategy_compositor.h"

class GlyphStrategyCompositorSimple : public GlyphStrategyCompositor
{
    public:
        GlyphStrategyCompositorSimple();
        
        virtual void compose() override;
};

#endif /* ifndef __GLYPH_STRATEGY_COMPOSITOR_SIMPLE_H__ */
