#ifndef __CONSOLE_WIDGET_H__
#define __CONSOLE_WIDGET_H__ 

#include "clock_timer.hpp"
#include "console_window.hpp"
#include "observer.hpp"
#include "subject.hpp"
#include <memory>
#include <string>

class ConsoleWidget : public ConsoleWindow, public Observer
{
    private:
        int _cx;
        int _cy;
        int _width;
        int _height;
        ClockTimer::Ptr _subject;

    public:
        ConsoleWidget(ClockTimer::Ptr, int, int, int, int);
        virtual ~ConsoleWidget();

    protected:
        ClockTimer::Ptr subject();

    public:
        int cx();
        int cy();
        int width();
        int height();

        virtual void update(std::shared_ptr<Subject>);

        virtual void draw();
        void draw_frame(std::string title);
};

#endif /* ifndef __CONSOLE_WIDGET_H__ */
