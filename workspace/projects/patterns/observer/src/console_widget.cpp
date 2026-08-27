#include "console_widget.hpp"
#include <iostream>
#include <memory>
#include <string>

ConsoleWidget::ConsoleWidget(ClockTimer::Ptr subject, int x, int y, int w, int h) : _subject(subject), _cx(x), _cy(y), _width(w), _height(h) {}

ConsoleWidget::~ConsoleWidget() {}

ClockTimer::Ptr ConsoleWidget::subject() { return _subject; }

int ConsoleWidget::cx() { return _cx; }
int ConsoleWidget::cy() { return _cy; }
int ConsoleWidget::width() { return _width; }
int ConsoleWidget::height() { return _height; }

void ConsoleWidget::update(std::shared_ptr<Subject> subject) 
{
    if (_subject == subject)
        draw();
}

void ConsoleWidget::draw() {}

void ConsoleWidget::draw_frame(std::string title) 
{
    // top border
    std::cout << "\033[" << cy() << ";" << cx() << "H┌ " << title << " ";
    for (int i = title.length() + 3; i < width() - 1; ++i) std::cout << "―";
    std::cout << "┐";

    // side borders
    for (int y = 1; y < _height - 1; ++y)
    {
        std::cout << "\033[" << (cy() + y) << ";" << cx() << "H│";
        std::cout << "\033[" << (cy() + y) << ";" << (cx() + width() - 1) << "H│";
    }

    // bottom border
    std::cout << "\033[" << (cy() + height() - 1) << ";" << cx() << "H└";
    for (int i = 1; i < width() - 1; ++i) std::cout << "―";
    std::cout << "┘";
}
