#include "clock_analog.hpp"
#include "clock_timer.hpp"
#include "console_widget.hpp"
#include <cmath>
#include <iostream>
#include <memory>

ClockAnalog::ClockAnalog(ClockTimer::Ptr s, int x, int y, int w, int h, int r, int ax, int ay): 
    ConsoleWidget(s, x, y, w, h), _radius(r), _ax(ax), _ay(ay) { subject()->attach(this); }

ClockAnalog::~ClockAnalog() { subject()->detach(this); }

ClockAnalog::Ptr ClockAnalog::create(ClockTimer::Ptr timer, int x, int y, int w, int h, int r, int ax, int ay)
{
    return std::make_shared<ClockAnalog>(timer, x, y, w, h, r, ax, ay);
}

int ClockAnalog::ax() { return _ax; }
int ClockAnalog::ay() { return _ay; }

void ClockAnalog::draw()
{
    draw_frame("Analog");
    // draw the analog clock
    draw_dial();

    // old times
    int phour = subject()->hour(true), 
        pminute = subject()->minute(true), 
        psecond = subject()->second(true);

    int hour    = subject()->hour(),
        minute  = subject()->minute(),
        second  = subject()->second();

    // old hands
    double pSecHand = psecond * M_PI / 30 - M_PI / 2;
    double pMinHand = pminute * M_PI / 30 - M_PI / 2;
    double pHrHand = (phour % 12 + pminute / 60.0) * M_PI / 6 - M_PI / 2;

    // reset old hands
    if(phour != hour)       draw_hand(' ', 0.5, pHrHand, 32);
    if(pminute != minute)   draw_hand(' ', 0.8, pMinHand, 36);
    if(psecond != second)   draw_hand(' ', 1.0, pSecHand, 31);

    // Hands calculations
    double secHand = second * M_PI / 30 - M_PI / 2;
    double minHand = minute * M_PI / 30 - M_PI / 2;
    double hrHand = (hour % 12 + minute / 60.0) * M_PI / 6 - M_PI / 2;

    // Draw seconds hand pointer (.)
    draw_hand('.', 1.0, secHand, 31);
    draw_hand('o', 0.8, minHand, 36);
    draw_hand('O', 0.5, hrHand, 32);

/*     phour = hour; */
    /* pminute = minute; */
    /* psecond = second; */
}

void ClockAnalog::draw_dial()
{
    // draw dial points/numbers
    for(int i = 0; i < 12; ++i)
    {
        double angle = i * M_PI / 6 - M_PI / 2;
        int px = (int) (ax() + (_radius * 1.8) * std::cos(angle));
        int py = (int) (ay() + (_radius * 0.9) * std::sin(angle));
        std::cout << "\033[" << py << ";" << px << "H" << (i == 0 ? 12 : i);
    }
}

void ClockAnalog::draw_hand(char ch, double percent, double angle, int color)
{
    for (double r = 1; r <= _radius * percent; ++r)
    {
        int sx = (int)(ax() + (r * 1.5) * std::cos(angle));
        int sy = (int)(ay() + (r * 0.75) * std::sin(angle));
        std::cout << "\033[" << sy << ";" << sx << "H\033[" << color << "m" << ch << "\033[0m";
    }
}
