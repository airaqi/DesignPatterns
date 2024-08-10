#include "compositor_simple.h"
#include <iostream>

SimpleCompositor::SimpleCompositor()
{
    std::cout << "SimpleCompositor::SimpleCompositor()\n";
}

int SimpleCompositor::compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]) 
{
    std::cout << "SimpleCompositor::compose()\n";
    return 0;
}
