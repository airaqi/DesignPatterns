#ifndef __APPLICATION_MENU_BASE_H__
#define __APPLICATION_MENU_BASE_H__ 

#include <cstring>
class BaseMenu
{
    public:
        BaseMenu(const char* name) { if (name) std::strcpy(_name, name); }
        virtual ~BaseMenu() {}

        virtual void display(const char* = "", const char* ="") = 0;
        virtual void clicked() = 0;

        virtual void add(BaseMenu*) = 0;
        virtual void insert(BaseMenu*, int) = 0;
        virtual void remove(BaseMenu*) = 0;
        
        virtual BaseMenu* get(int) const = 0;

    protected:
        char _name[256];


};

#endif /* ifndef __APPLICATION_MENU_BASE_H__ */
