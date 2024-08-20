#include "window.h"
#include "factory_window_system.h"
#include "window_imp.h"

BWindow::BWindow(View* contents) : 
    _contents(contents), 
    _imp(nullptr), 
    _rect(0, 0, 320, 200) {}

BWindow::~BWindow()
{
    delete _contents;
    delete _imp;
    WindowSystemFactory::reset();
}

void BWindow::drawContents()
{
    _contents->draw(this);
}

void BWindow::setOrigin(const Point& at) 
{
    _rect.origin(at);
}

void BWindow::setExtent(const Point& ext) 
{
    _rect.extent(ext);
}

Point& BWindow::getOrigin()
{
    return _rect.origin();
}

Point& BWindow::getExtent()
{
    return _rect.extent();
}

WindowImp* BWindow::getWindowImp()
{
    if (_imp == nullptr)
        _imp = WindowSystemFactory::instance().createWindow();
    return _imp;
}

View* BWindow::getView()
{
    return _contents;
}


