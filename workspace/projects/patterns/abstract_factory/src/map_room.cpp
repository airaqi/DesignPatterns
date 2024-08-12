#include "map_room.h"
#include "map_direction.h"
#include "map_site.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

Room::Room(int roomNo) : _roomNumber(roomNo)
{
    _sides[North] = nullptr;
    _sides[South] = nullptr;
    _sides[East] = nullptr;
    _sides[West] = nullptr;
}

Room::~Room()
{
    for (Direction d(North); d <= West; d = static_cast<Direction>(d+1))
        if (!_sides[d]->isDoor())
            delete _sides[d];
        else
            if (_sides[d]->marked())
                delete _sides[d];
            else
                _sides[d]->mark();
}

MapSite* Room::getSide(Direction direction) const
{
    return _sides[direction];
}

void Room::setSide(Direction direction, MapSite* side)
{
    if (_sides[direction] != nullptr && !(_sides[direction]->isDoor()))
        delete _sides[direction];
    _sides[direction] = side;
}

int Room::roomNumber() 
{
    return _roomNumber;
}

void Room::enter()
{
   std::cout << "You've just entereed " << to_string() << "\n"; 
}


std::string Room::to_string()
{
    std::stringstream out;
    out << "[Room: " << roomNumber() << " - ("
        << "N: " << getSide(North) << ", "
        << "S: " << getSide(South) << ", "
        << "E: " << getSide(East) << ", "
        << "W: " << getSide(West) 
        << ")]";
    return out.str();
}
