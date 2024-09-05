#include "window_imp_x.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

WindowImpX::WindowImpX() : _running(true)
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
    XSelectInput(_display, _window, KeyPressMask | KeyReleaseMask | ExposureMask);
    XStoreName(_display, _window, "Hello Bridge!");

    // show window
    XClearWindow(_display, _window);
    XMapRaised(_display, _window);
    XSync(_display, false);

    // initialize graphics context
    _gc = XDefaultGC(_display, _screenId);
}

WindowImpX::~WindowImpX()
{
    XDestroyWindow(_display, _window);
    XCloseDisplay(_display);
}

void WindowImpX::impTop()
{
}

void WindowImpX::impBottom()
{
}

void WindowImpX::impSetExtent(const Point&)
{}

void WindowImpX::impSetOrigin(const Point&)
{
}

void WindowImpX::deviceRect(Coord x1, Coord y1, Coord x2, Coord y2)
{
    int x = std::round(std::min(x1, x2));
    int y = std::round(std::min(y1, y2));
    int w = std::round(std::abs(x1 - x2));
    int h = std::round(std::abs(y1 - y2));

    XDrawRectangle(_display, _window, _gc, x, y, w, h);
}

void WindowImpX::deviceText(const char* str, Coord x, Coord y)
{
    XDrawString(_display, _window, _gc, x, y, str, std::strlen(str));
}

void WindowImpX::deviceBitMap(const char*, Coord, Coord)
{
}

void WindowImpX::event_loop(BWindow* win)
{
    XEvent event;
    char str[25];
    str[0] = 0;
    int len = 0;
    KeySym keysym = 0;
    while(_running) 
    {
        XNextEvent(_display, &event);
        switch (event.type) 
        {
            case KeyRelease:
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
