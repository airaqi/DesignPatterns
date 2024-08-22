#include "document.hpp"
#include <cstring>
#include <iostream>


Document::Document(const char* name) 
{
    std::strcpy(_name, name);
}
Document::~Document() {}

void Document::open()
{
    std::cout << "document '" << _name << "' opened!\n";
}

void Document::close()
{
    std::cout << "document '" << _name << "' closed!\n";
}

void Document::cut()
{
    std::cout << "document '" << _name << "' cut\n";
}

void Document::copy()
{
    std::cout << "document '" << _name << "' copy\n";
}   

void Document::paste()
{
    std::cout << "document '" << _name << "' paste!\n";
}

bool operator==(const Document& lhs, const Document& rhs)
{
    return (std::strcmp(rhs._name, lhs._name) == 0);
}
