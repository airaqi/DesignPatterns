#include "decorator_scroll.h"
#include "decorator.h"
#include "visual_component.h"
#include <iostream>

DecoratorScroll::DecoratorScroll(VisualComponent* component) : Decorator(component) {}

void DecoratorScroll::draw()
{
    std::cout << "DecoratorScroll::draw()\n";
    Decorator::draw();
    draw_scroll();
}

void DecoratorScroll::draw_scroll()
{
    std::cout << "DecoratorScroll::draw_scroll()\n";
}
