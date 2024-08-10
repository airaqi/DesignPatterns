#ifndef __TEX_COMPOSITOR_H__
#define __TEX_COMPOSITOR_H__ 

#include "compositor.h"
class TeXCompositor : public Compositor
{
    public:
        TeXCompositor();
        virtual int compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]);
};

#endif /* ifndef __TEX_COMPOSITOR_H__ */
