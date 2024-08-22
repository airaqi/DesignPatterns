#ifndef __APPLICATION_MENUITEM_H__
#define __APPLICATION_MENUITEM_H__ 

#include "application_menu_base.hpp"
#include "command.hpp"

class MenuItem : public BaseMenu
{
    public: 
        MenuItem(const char* name, Command* command);
        virtual ~MenuItem();

        virtual void display(const char* = "", const char* = "") override;
        virtual void clicked() override;

        virtual void add(BaseMenu*) override;
        virtual void insert(BaseMenu *, int) override;
        virtual void remove(BaseMenu*) override;

        virtual BaseMenu* get(int) const override;

    private:
        Command* _command;
};

#endif /* ifndef __APPLICATION_MENUITEM_H__ */
