#include "application_menu.hpp"
#include "application_menu_base.hpp"
#include "list_iterator.h"
#include <cstring>
#include <iostream>


Menu::Menu(const char* name) : BaseMenu(name) {}

Menu::~Menu() {}


void Menu::display(const char* prefix, const char* postfix)
{
    std::cout << _name << std::endl;
    ListIterator<BaseMenu*> i(&_children);
    for (i.first(); !i.is_done(); i.next())
        i.currentItem()->display("--> ");
}


void Menu::clicked()
{}


void Menu::add(BaseMenu* item)
{
    _children.append(item);
}


void Menu::insert(BaseMenu* item, int index)
{
    _children.insert(item, index);
}


void Menu::remove(BaseMenu* item)
{
    _children.remove(item);
}


BaseMenu* Menu::get(int index) const
{
    return _children.get(index);
}
