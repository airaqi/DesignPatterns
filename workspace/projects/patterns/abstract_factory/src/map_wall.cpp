#include "map_wall.h"
#include <iostream>
#include <string>

Wall::Wall() {}

Wall::~Wall() {}

// Part of prototype pattern implementation
Wall* Wall::clone()
{
    return new Wall(*this);
}

void Wall::enter()
{
    std::cout << "You've just hurt your nose!\n";
}

std::string Wall::to_string()
{
    return std::string("[Wall]");
}
