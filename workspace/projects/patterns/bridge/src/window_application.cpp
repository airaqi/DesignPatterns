#include "window_application.h"

WindowApplication::WindowApplication(View* contents) : BWindow(contents) {}

WindowApplication::~WindowApplication() {}

void WindowApplication::drawContents()
{
    getView()->draw(this);
}


void WindowApplication::drawLine(const Point& p1, const Point& p2) 
{}

void WindowApplication::drawRect(const Point& p1, const Point& p2)
{
    getWindowImp()->deviceRect(p1.x(), p1.y(), p2.x(), p2.y());
}

void WindowApplication::drawPolygon(const Point[], int n) {}

void WindowApplication::drawText(const char* str, const Point& p) 
{
    getWindowImp()->deviceText(str, p.x(), p.y());
}

void WindowApplication::run_loop()
{
    getWindowImp()->run_loop(this);
}

