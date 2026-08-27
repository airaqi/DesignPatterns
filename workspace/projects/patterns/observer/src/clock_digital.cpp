#include "clock_digital.hpp"
#include "clock_timer.hpp"
#include "console_widget.hpp"
#include <iomanip>
#include <iostream>
#include <memory>

ClockDigital::ClockDigital(ClockTimer::Ptr sub, int x, int y, int w, int h) : 
    ConsoleWidget(sub, x, y, w, h) { subject()->attach(this); }

ClockDigital::~ClockDigital() { subject()->detach(this); }

ClockDigital::Ptr ClockDigital::create(ClockTimer::Ptr subject, int x, int y, int w, int h) { return std::make_shared<ClockDigital>(subject, x, y, w, h); }

void ClockDigital::draw()
{
    // TODO draw the digital clock
    draw_frame("Digital");

    std::cout 
        << "\033[" << (cy() + 1) << ";" << (cx() + 2) << "H\033[1mTime: "
        << std::setfill('0') << std::setw(2) << subject()->hour() << ":"
        << std::setfill('0') << std::setw(2) << subject()->minute() << ":"
        << std::setfill('0') << std::setw(2) << subject()->second();
}
