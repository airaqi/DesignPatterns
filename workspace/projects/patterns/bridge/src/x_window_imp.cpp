#include "x_window_imp.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

XWindowImp::XWindowImp() : _running(true)
{
    // open display 
    _display = XOpenDisplay(nullptr);
    if (_display == nullptr)
        std::cout << "Couldn't open display!\n";

    _screen = DefaultScreenOfDisplay(_display);
    _screenId = DefaultScreen(_display);

    // open the window
    _window = XCreateSimpleWindow(
            _display, 
            RootWindowOfScreen(_screen), 
            0, 0, 320, 200, 1, 
            BlackPixel(_display, _screenId), 
            WhitePixel(_display, _screenId));
    XSelectInput(_display, _window, KeyPressMask | ExposureMask);
    XStoreName(_display, _window, "Hello Bridge!");

    // show window
    XClearWindow(_display, _window);
    XMapRaised(_display, _window);

    // initialize graphics context
    _gc = XDefaultGC(_display, _screenId);
}

XWindowImp::~XWindowImp()
{
    XDestroyWindow(_display, _window);
    XCloseDisplay(_display);
}

void XWindowImp::impTop()
{
}

void XWindowImp::impBottom()
{
}

void XWindowImp::impSetExtent(const Point&)
{
}

void XWindowImp::impSetOrigin(const Point&)
{
}

void XWindowImp::deviceRect(Coord x1, Coord y1, Coord x2, Coord y2)
{
    int x = std::round(std::min(x1, x2));
    int y = std::round(std::min(y1, y2));
    int w = std::round(std::abs(x1 - x2));
    int h = std::round(std::abs(y1 - y2));

    XDrawRectangle(_display, _window, _gc, x, y, w, h);
}

void XWindowImp::deviceText(const char* str, Coord x, Coord y)
{
    XDrawString(_display, _window, _gc, x, y, str, std::strlen(str));
}

void XWindowImp::deviceBitMap(const char*, Coord, Coord)
{
}

void XWindowImp::run_loop(BWindow* win)
{
    XEvent event;
    char str[25];
    str[0] = 0;
    int len = 0;
    KeySym keysym = 0;
    while(_running) {
        XNextEvent(_display, &event);
        switch (event.type) {
            case KeyPress:
                len = XLookupString(&event.xkey, str, 25, &keysym, nullptr);
                if(keysym == XK_Escape)
                    _running = false;
                break;
            case Expose:
                win->drawContents();
                break;
        }
    }   
}
