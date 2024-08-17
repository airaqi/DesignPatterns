#include "window.h"
#include "factory_window_system.h"
#include "window_imp.h"

BWindow::BWindow(View* contents) : _contents(contents), _imp(nullptr) {}

BWindow::~BWindow()
{
    delete _contents;
    delete _imp;
}

void BWindow::drawContents()
{
    _contents->draw(this);
}

void BWindow::open() {}

void BWindow::close() {}

void BWindow::iconify() {}

void BWindow::deiconify() {}

void BWindow::setOrigin(const Point& at) {}

void BWindow::setExtent(const Point& ext) {}

void BWindow::raise() {}

void BWindow::lower() {}

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


