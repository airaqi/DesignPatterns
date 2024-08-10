#ifndef __ARRAY_COMPOSITOR_H__
#define __ARRAY_COMPOSITOR_H__ 

#include "compositor.h"
class ArrayCompositor : public Compositor
{
    public:
        ArrayCompositor();
        virtual int compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]);
};

#endif /* ifndef __ARRAY_COMPOSITOR_H__ */
