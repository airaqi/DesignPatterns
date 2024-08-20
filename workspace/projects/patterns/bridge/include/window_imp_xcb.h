#ifndef __WINDOW_IMP_XCB_H__
#define __WINDOW_IMP_XCB_H__ 

#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include "window_imp.h"

class WindowImpXcb : public WindowImp
{
    public:
        WindowImpXcb();
        virtual ~WindowImpXcb();

        virtual void impTop();
        virtual void impBottom();
        virtual void impSetExtent(const Point&);
        virtual void impSetOrigin(const Point&);

        virtual void deviceRect(Coord, Coord, Coord, Coord);
        virtual void deviceText(const char*, Coord, Coord);
        virtual void deviceBitMap(const char*, Coord, Coord);

        virtual void event_loop(BWindow*);

    private:
        xcb_connection_t*   _c;
        xcb_screen_t*       _screen;
        xcb_window_t        _window;
        xcb_gcontext_t      _forground;
        xcb_font_t          _font;

        bool _running;
};

#endif /* ifndef __WINDOW_IMP_XCB_H__ */
