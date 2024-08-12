#include "decorator_border.h"
#include "decorator_scroll.h"
#include "text_view.h"
#include "visual_component.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello decorator pattern!\n";

   TextView* view = new TextView; 
   DecoratorBorder* border = new DecoratorBorder(view, 5);
   DecoratorScroll* scroll = new DecoratorScroll(border);
   VisualComponent* component = scroll;

   component->draw();

   delete component;

    return 0;
}
