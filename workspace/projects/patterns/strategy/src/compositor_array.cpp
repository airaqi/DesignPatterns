#include "compositor_array.h"
#include "compositor.h"
#include <iostream>

ArrayCompositor::ArrayCompositor()
{
    std::cout << "ArrayCompositor::ArrayCompositor()\n";
}

int ArrayCompositor::compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]) 
{
    std::cout << "ArrayCompositor::compose()\n";
    return 0;
}
