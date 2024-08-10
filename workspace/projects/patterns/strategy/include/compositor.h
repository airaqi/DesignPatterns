#ifndef __COMPOSITOR_H__
#define __COMPOSITOR_H__ 

#include "coord.h"


class Compositor
{
    public:
        virtual ~Compositor() {}
        virtual int compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]) = 0;

    protected:
        Compositor();
};

#endif /* ifndef __COMPOSITOR_H__ */
