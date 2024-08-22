#ifndef __APPLICATION_MENU_H__
#define __APPLICATION_MENU_H__ 

#include "application_menu_base.hpp"
#include "list.h"

class Menu : public BaseMenu
{
    public:
        Menu(const char* name);
        virtual ~Menu();

        virtual void display(const char* ="",const char* ="") override;
        virtual void clicked() override;

        virtual void add(BaseMenu*) override;
        virtual void insert(BaseMenu*, int) override;
        virtual void remove(BaseMenu*) override;
        
        virtual BaseMenu* get(int) const override;

    private:
        List<BaseMenu*> _children;
};

#endif /* ifndef __APPLICATION_MENU_H__ */
