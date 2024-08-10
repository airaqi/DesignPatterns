#include "decorator_border.h"
#include "decorator.h"
#include <iostream>

DecoratorBorder::DecoratorBorder(VisualComponent* component, int width) : 
    Decorator(component), _width(width) {}

void DecoratorBorder::draw()
{
    std::cout << "DecoratorBorder::draw()\n";
    Decorator::draw();
    draw_border(_width);
}

void DecoratorBorder::draw_border(int width)
{
    std::cout << "DecoratorBorder::draw_border(" << width << ")\n";
}
