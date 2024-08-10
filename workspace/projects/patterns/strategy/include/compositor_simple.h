#ifndef __SIMPLE_COMPOSITOR_H__
#define __SIMPLE_COMPOSITOR_H__

#include "compositor.h"
class SimpleCompositor : public Compositor 
{
    public:
        SimpleCompositor();
        virtual int compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]);
};

#endif /* ifndef __SIMPLE_COMPOSITOR_H__ */
