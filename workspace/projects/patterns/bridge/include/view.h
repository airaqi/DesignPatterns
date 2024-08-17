#ifndef __VIEW_H__
#define __VIEW_H__ 

class BWindow;

class View
{
    public:
        View() {}
        virtual ~View() {}

        virtual void draw(BWindow*) = 0;
};

#endif /* ifndef __VIEW_H__ */
