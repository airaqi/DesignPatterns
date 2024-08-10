#include "text_view.h"
#include <iostream>

TextView::TextView() {}

TextView::~TextView() {}

void TextView::draw()
{
    std::cout << "TextView::draw()\n";
}

void TextView::resize()
{
    std::cout << "TextView::resize()\n";
}
