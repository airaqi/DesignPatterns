#include "document.hpp"
#include <cstring>
#include <iostream>


Document::Document(const char* name) : _name(name) {}
Document::~Document() 
{ 
    delete[] _name; 
    _name = nullptr;
}

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


