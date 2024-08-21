#include "document.hpp"
#include <iostream>


Document::Document(const char* name) : _name(name) {}
Document::~Document() {}

void Document::open()
{
    std::cout << "document " << _name << " opened!\n";
}

void Document::close()
{
    std::cout << "document " << _name << " closed!\n";
}

void Document::cut()
{
}

void Document::copy()
{
}   

void Document::paste()
{
}


