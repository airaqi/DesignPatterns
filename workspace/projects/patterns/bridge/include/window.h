#ifndef __WINDOW_H__
#define __WINDOW_H__ 

#include "point.h"
#include "view.h"
#include "window_imp.h"

class Window
{
    public:
        Window(View* contents);

        // requests handled by window
        virtual void drawContents();

        virtual void open();
        virtual void close();
        virtual void iconify();
        virtual void deiconify();

        // requests forwarded to implementation
        virtual void setOrigin(const Point& at);
        virtual void setExtent(const Point& ext);
        virtual void raise();
        virtual void lower();

        virtual void drawLine(const Point&, const Point&);
        virtual void drawRect(const Point&, const Point&);
        virtual void drawPolygon(const Point[], int n);
        virtual void drawText(const char*, const Point&);

    protected:
        WindowImp* getWindowImp();
        View* getView();

    private:
        WindowImp* _imp;
        View* _contents;
};

#endif /* ifndef __WINDOW_H__ */
