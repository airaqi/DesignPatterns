#include "manipulator.hpp"
#include "point.h"
#include "shape_text.hpp"
#include "shape_text_object.hpp"
#include "text_view.hpp"
#include <iostream>

void classAdapter()
{
    const char* str = "Hello";
    Point bl(10, 30), tr(60, 10);

    TextShapeClass text(bl, tr, str);
    Point bottomLeft, topRight;

    text.boundingBox(bottomLeft, topRight);
    std::cout 
        << "creating TextShape Text: " << str
        << " bottomLeft: " << bottomLeft 
        << " topRight: " << topRight 
        << "\n";

    text.doSomthing();

    std::cout 
        << "TextShape: \n"
        << text << "\n";

    Point mp(10, 10);
    std::cout << "Moving TextShape by " << mp << "\n";

    Manipulator* manipulator = text.createManipulator();
    manipulator->move(mp);

    std::cout 
        << "We get TextShape: "
        << text << "\n\n\n";

    delete manipulator;

}

void objectAdapter()
{
    const char* str = "Hello";
    Point bl(10, 30), tr(60, 10);

    TextView view(10, 10, 50, 20, str);
    TextShapeObject text(&view);

    Point bottomLeft, topRight;

    text.boundingBox(bottomLeft, topRight);
    std::cout 
        << "creating TextShape Text: " << str
        << " bottomLeft: " << bottomLeft 
        << " topRight: " << topRight 
        << "\n";

    text.doSomthing();

    std::cout 
        << "TextShape: \n"
        << text << "\n";

    Point mp(10, 10);
    std::cout << "Moving TextShape by " << mp << "\n";

    Manipulator* manipulator = text.createManipulator();
    manipulator->move(mp);

    std::cout 
        << "We get TextShape: "
        << text << "\n\n\n";

    delete manipulator;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello, Prototype!\n";
    classAdapter();
    objectAdapter();;
    return 0;
}
