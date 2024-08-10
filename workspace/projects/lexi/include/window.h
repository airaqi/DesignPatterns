#ifndef __WINDOW_H__
#define __WINDOW_H__ 

#include <iostream>
#include <string>
class Window 
{
    public:
        Window() {}

        void rectangle(long x, long y, long w, long h) { std::cout << "Window::rectangle()\n"; }
        void text(long x, long y, std::string s) { std::cout << "Window::text()\n"; }
};

#endif /* ifndef __WINDOW_H__ */
