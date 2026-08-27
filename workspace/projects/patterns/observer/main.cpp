#include "clock_analog.hpp"
#include "clock_digital.hpp"
#include "clock_timer.hpp"
#include "console_window.hpp"
#include "window.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    int timeout = 30;
    std::cout << "Hello, Prototype!\n";

    ConsoleWindow window;
    ClockTimer::Ptr timer = ClockTimer::create(1000);

    ClockDigital::Ptr dclock = ClockDigital::create(timer);
    ClockAnalog::Ptr aclock = ClockAnalog::create(timer);
    
    window.add(dclock);
    window.add(aclock);

    window.start();

    return 0;
}
