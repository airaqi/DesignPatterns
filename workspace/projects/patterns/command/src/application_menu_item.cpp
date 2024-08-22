#include "application_menu_item.hpp"
#include <iostream>


MenuItem::MenuItem(const char* name, Command* command) : BaseMenu(name), _command(command) {}
MenuItem::~MenuItem() {}

void MenuItem::display(const char* prefix, const char* postfix)
{
    std::cout << prefix << _name << postfix << std::endl;
}

void MenuItem::clicked()
{
    _command->execute();
}

void MenuItem::add(BaseMenu* item) {}

void MenuItem::insert(BaseMenu*, int) {}

void MenuItem::remove(BaseMenu*) {}

BaseMenu* MenuItem::get(int) const
{
    return nullptr;
}



