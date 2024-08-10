#include "decorator.h"
#include "visual_component.h"
#include <iostream>

Decorator::Decorator(VisualComponent* component) : _component(component) {}

Decorator::~Decorator()
{
    delete _component;
}

void Decorator::draw()
{
    std::cout << "Decorator::draw()\n";
    _component->draw();
}

void Decorator::resize()
{
    std::cout << "Decorator::resize()\n";
    _component->resize();
}
