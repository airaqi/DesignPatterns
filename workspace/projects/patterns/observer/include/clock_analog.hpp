#ifndef __CLOCK_ANALOG_H__
#define __CLOCK_ANALOG_H__ 

#include "clock_timer.hpp"
#include "console_widget.hpp"
#include <memory>

class ClockAnalog : public ConsoleWidget
{
    private:
        int _radius;
        int _ax, _ay;

    public:
        using Ptr = std::shared_ptr<ClockAnalog>;
        static Ptr create(ClockTimer::Ptr, int=2, int=2, int=40, int=15, int=6, int=21, int=9);

        ClockAnalog(ClockTimer::Ptr, int=2, int=2, int=40, int=15, int=6, int=21, int=9);
        virtual ~ClockAnalog();

        int ax();
        int ay();

        virtual void draw();

        void draw_dial();
        void draw_hand(char ch, double percent, double angle, int color);
};

#endif /* ifndef __CLOCK_ANALOG_H__ */
