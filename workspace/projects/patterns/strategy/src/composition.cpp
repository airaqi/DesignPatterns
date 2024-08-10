#include "composition.h"
#include "compositor.h"

Composition::~Composition()
{
    if (_compositor != nullptr)
        delete _compositor;
    if (_components != nullptr)
        delete[] _components;
}

void Composition::repair()
{
    Coord* natural;
    Coord* stretchability;
    Coord* shrinkability;
    int componentCount;
    int* breaks;

    // prepare the arrays with the desired component sizes
    // ...

    // determine where the breaks are
    int breakCount;
    breakCount = _compositor->compose(natural, stretchability, shrinkability, componentCount, _line_width, breaks);

    // layout components according to breaks.
    // ...
}
