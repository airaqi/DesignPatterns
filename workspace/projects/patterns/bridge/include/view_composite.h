#ifndef __VIEW_COMPOSITE_H__
#define __VIEW_COMPOSITE_H__ 

#include "list.h"
#include "view.h"

class ViewComposite : public View
{
    public:
        ViewComposite();
        virtual ~ViewComposite();

        virtual void draw(BWindow *) override;

        virtual void append(View*);
        virtual void prepend(View*);
        virtual void insert(View*, int);
        virtual View* get_child(int);

    private:
        List<View*>* _children;
};

#endif /* ifndef __VIEW_COMPOSITE_H__ */
