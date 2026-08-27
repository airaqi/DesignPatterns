#ifndef __CONSOLE_WINDOW_H__
#define __CONSOLE_WINDOW_H__ 

#include "window.hpp"
#include <vector>
class ConsoleWindow : public Window
{
    private:
        std::vector<Window::Ptr> _children;
        bool _start = true;
        int _timeout = 30;

    public:
        ConsoleWindow(int=30);

        virtual void draw();

        virtual void add(Window::Ptr);
        virtual void set(int, Window::Ptr);
        virtual Window::Ptr remove(int);

        void start();
        void stop();
        void clear();
        void flush();
        void sleep(int);


};

#endif /* ifndef __CONSOLE_WINDOW_H__ */
