#include "application_window.h"

ApplicationWindow::ApplicationWindow(View* contents) : Window(contents)
{
}

void ApplicationWindow::drawContents()
{
    getView()->draw();
}
