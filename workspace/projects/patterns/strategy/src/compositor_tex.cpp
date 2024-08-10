#include "compositor_tex.h"
#include "compositor.h"
#include <iostream>

TeXCompositor::TeXCompositor()
{
    std::cout << "TeXCompositor::TeXCompositor()\n";
}

int TeXCompositor::compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int linewidth, int breaks[]) 
{
    std::cout << "TeXCompositor::compose()\n";
    return 0;
}
