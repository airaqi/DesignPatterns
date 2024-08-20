#ifndef __X_APPLICATION_WINDOW_H__
#define __X_APPLICATION_WINDOW_H__ 

#include <X11/X.h>
#include <X11/Xlib.h>

#include "window.h"
#include "window_imp.h"

class WindowImpX : public WindowImp
{
    public:
        WindowImpX();
        virtual ~WindowImpX();

        virtual void impTop();
        virtual void impBottom();
        virtual void impSetExtent(const Point&);
        virtual void impSetOrigin(const Point&);

        virtual void deviceRect(Coord, Coord, Coord, Coord);
        virtual void deviceText(const char*, Coord, Coord);
        virtual void deviceBitMap(const char*, Coord, Coord);

        virtual void event_loop(BWindow*);

    private:
        Display* _display;
        Window _window;
        Screen* _screen;
        int _screenId;
        GC _gc;
        bool _running;
};

#endif /* ifndef __X_APPLICATION_WINDOW_H__ */
