#ifndef __WINDOW_H__
#define __WINDOW_H__ 

#include "point.h"
#include "rect.h"
#include "view.h"
#include "window_imp.h"

class BWindow
{
    public:
        BWindow(View* contents);
        virtual ~BWindow();

        // requests handled by window
        virtual void drawContents();

        virtual void open() = 0;
        virtual void close() = 0;
        virtual void iconify() = 0;
        virtual void deiconify() = 0;

        // requests forwarded to implementation
        virtual void setOrigin(const Point& at);
        virtual void setExtent(const Point& ext);
        virtual Point& getOrigin();
        virtual Point& getExtent();

        virtual void raise() = 0;
        virtual void lower() = 0;

        virtual void drawLine(const Point&, const Point&) = 0;
        virtual void drawRect(const Point&, const Point&) = 0;
        virtual void drawPolygon(const Point[], int n) = 0;
        virtual void drawText(const char*, const Point&) = 0;

        virtual void run_loop() = 0;

    protected:
        WindowImp* getWindowImp();
        View* getView();

    private:
        WindowImp* _imp;
        View* _contents;
        Rect _rect;
};

#endif /* ifndef __WINDOW_H__ */
