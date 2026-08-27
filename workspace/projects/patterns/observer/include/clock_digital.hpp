#ifndef __CLOCK_DIGITAL_H__
#define __CLOCK_DIGITAL_H__ 

#include "clock_timer.hpp"
#include "console_widget.hpp"
#include <memory>

class ClockDigital : public ConsoleWidget
{

    public:
        using Ptr = std::shared_ptr<ClockDigital>;
        static Ptr create(ClockTimer::Ptr, int=45, int=2, int=26, int=5);

        ClockDigital(ClockTimer::Ptr, int=45, int=2, int=26, int=5);
        virtual ~ClockDigital();

        virtual void draw();
};

#endif /* ifndef __CLOCK_DIGITAL_H__ */
