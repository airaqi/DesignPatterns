#ifndef __APPLICATION_WINDOW_H__
#define __APPLICATION_WINDOW_H__ 

#include "window.h"

class WindowApplication : public BWindow
{
    public:
        WindowApplication(View* contents);
        virtual ~WindowApplication();

        virtual void drawContents() override;

        virtual void drawLine(const Point&, const Point&) override;
        virtual void drawRect(const Point&, const Point&) override;
        virtual void drawPolygon(const Point[], int n) override;
        virtual void drawText(const char*, const Point&) override;
        virtual void run_loop() override;


};
#endif /* ifndef __APPLICATION_WINDOW_H__ */
