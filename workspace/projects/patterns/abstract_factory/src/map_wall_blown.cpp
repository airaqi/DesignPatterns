#include "map_wall_blown.h"
#include <iostream>

WallBlown::WallBlown() : _is_blown(false) {}

WallBlown::~WallBlown() {}

// Part of prototype pattern implementation
WallBlown* WallBlown::clone()
{
    return new WallBlown(*this);
}

void WallBlown::enter()
{
    if (_is_blown)
        std::cout << "You've just been badly hurt!!!\n";
    else
        std::cout << "You've just broken your nose!\n";
}

void WallBlown::blow()
{
    _is_blown = true;
}

std::string WallBlown::to_string()
{
    return std::string("[WallBlown]");
}
