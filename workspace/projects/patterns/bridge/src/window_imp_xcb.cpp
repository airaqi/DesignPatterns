#include "window_imp_xcb.h"
#include "window.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <xcb/xcb.h>
#include <xcb/xproto.h>


WindowImpXcb::WindowImpXcb() : _running(true), _screen(nullptr)
{
    int                     screen_number;
    const xcb_setup_t*      setup;
    xcb_screen_iterator_t   screen_iter;
    uint32_t                mask;
    uint32_t                values[4];
    xcb_void_cookie_t       cookie_window;
    xcb_void_cookie_t       cookie_map;
    xcb_generic_error_t*    error;

    // getting the connection
    _c = xcb_connect(nullptr, &screen_number);
    if (!_c) throw std::runtime_error("ERROR: can't connect to X server");

    // getting the current screen
    setup = xcb_get_setup(_c);

    screen_iter = xcb_setup_roots_iterator(setup);
    for (; screen_iter.rem != 0; --screen_number, xcb_screen_next(&screen_iter))
        if (screen_number == 0)
        {
            _screen = screen_iter.data;
            break;
        }

    if (!_screen)
    {
        xcb_disconnect(_c);
        throw std::runtime_error("ERROR: can't get the current screen");
    }

    // get font
    const char* fontname = "6x13";
    _font = xcb_generate_id(_c);
    xcb_void_cookie_t cookie_font = xcb_open_font_checked(_c, _font, std::strlen(fontname), fontname);
    error = xcb_request_check(_c, cookie_font);
    if (error)
    {
        xcb_disconnect(_c);
        throw std::runtime_error("ERROR: can't open font");
    }

    // create black forground graphic context
    _window = _screen->root;

    _forground = xcb_generate_id(_c);
    mask = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND | XCB_GC_FONT | XCB_GC_GRAPHICS_EXPOSURES;
    values[0] = _screen->black_pixel;
    values[1] = _screen->white_pixel;
    values[2] = _font;
    values[3] = 0;
    xcb_void_cookie_t cookie_gc = xcb_create_gc_checked(_c, _forground, _window, mask, values);
    error = xcb_request_check(_c, cookie_gc);
    if (error)
        throw std::runtime_error("ERROR: can't create gc");

    // create the window
    _window = xcb_generate_id(_c);
    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = _screen->white_pixel;
    values[1] = 
        XCB_EVENT_MASK_KEY_RELEASE |
        XCB_EVENT_MASK_BUTTON_PRESS | 
        XCB_EVENT_MASK_EXPOSURE | 
        XCB_EVENT_MASK_POINTER_MOTION;

    cookie_window = xcb_create_window_checked(
            _c, 
            _screen->root_depth, 
            _window, 
            _screen->root, 
            0, 0, 
            320, 200, 
            0, XCB_WINDOW_CLASS_INPUT_OUTPUT, 
            _screen->root_visual, 
            mask, values);
    cookie_map = xcb_map_window_checked(_c, _window);

    // error management
    error = xcb_request_check(_c, cookie_window);
    if (error)
    {
        throw std::runtime_error("ERROR: can't create window");
    }

    error = xcb_request_check(_c, cookie_map);
    if (error)
    {
        throw std::runtime_error("Error: can't map window");
    }

    // change the title of the window.
    const char* title = "Hello Bridge!";
    xcb_change_property(_c, XCB_PROP_MODE_REPLACE, _window, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, std::strlen(title), title);

    xcb_flush(_c);

}


WindowImpXcb::~WindowImpXcb() 
{
    xcb_close_font(_c, _font);
    xcb_free_gc(_c, _forground);
    xcb_disconnect(_c);
    std::cout << "destroy window" << "\n";
}


void WindowImpXcb::impTop()
{
}


void WindowImpXcb::impBottom()
{
}


void WindowImpXcb::impSetExtent(const Point&)
{}


void WindowImpXcb::impSetOrigin(const Point&)
{
}


void WindowImpXcb::deviceRect(Coord x1, Coord y1, Coord x2, Coord y2)
{
    int16_t x = x1, y = y1;
    uint16_t w=x2, h = y2;
    xcb_rectangle_t rectangles[] = { {.x=x, .y=y, .width=w, .height=h} };
    xcb_poly_rectangle(_c, _window, _forground, 1, rectangles);
    xcb_flush(_c);
}


void WindowImpXcb::deviceText(const char* label, Coord x, Coord y)
{
    xcb_void_cookie_t cookie_text = xcb_image_text_8_checked(_c, std::strlen(label), _window, _forground, x, y, label);
    xcb_generic_error_t* error = xcb_request_check(_c, cookie_text);
    if (error)
        throw std::runtime_error("ERROR: can't paste text");
}


void WindowImpXcb::deviceBitMap(const char*, Coord, Coord)
{
}


void WindowImpXcb::event_loop(BWindow* win)
{
    xcb_generic_event_t* event;

    while(_running)
    {
        event = xcb_poll_for_event(_c);
        if (!event) continue;

        switch (event->response_type & ~0x80) 
        {
        case XCB_EXPOSE:
            win->drawContents();
            break;

        case XCB_KEY_RELEASE:
            xcb_key_release_event_t* evt;
            evt = (xcb_key_release_event_t*) event;
            switch(evt->detail)
            {
                case 9:
                    free(event);
                    xcb_disconnect(_c);
                    exit(0);
                    break;
            }
            break;
        }
    }

    free(event);
}


