#include "composition.h"
#include "compositor_array.h"
#include "compositor_simple.h"
#include "compositor_tex.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, Strategy!\n";

    Composition* quick = new Composition(new SimpleCompositor());
    Composition* slick = new Composition(new TeXCompositor());
    Composition* iconic = new Composition(new ArrayCompositor());

    quick->repair();
    slick->repair();
    iconic->repair();

    delete quick;
    delete slick;
    delete iconic;

    return 0;
}
