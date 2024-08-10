#include "decorator_border.h"
#include "doctest_main.h"
#include "text_view.h"
#include "visual_component.h"

TEST_CASE("Test DecoratorBorder") {

   TextView* view = new TextView; 
   DecoratorBorder* border = new DecoratorBorder(view, 5);
   VisualComponent* component = border;

   component->draw();

   delete component;
} 
