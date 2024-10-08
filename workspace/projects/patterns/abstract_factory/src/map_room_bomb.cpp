#include "map_room_bomb.h"
#include "map_direction.h"
#include "map_wall_blown.h"
#include <iostream>
#include <sstream>
RoomBomb::RoomBomb(int roomNo) : Room(roomNo), _is_blowed(false) {}

RoomBomb::~RoomBomb() {}

// Part of prototype pattern implementation
RoomBomb* RoomBomb::clone()
{
    return new RoomBomb(*this);
}

void RoomBomb::enter()
{
    if(!_is_blowed) 
        blow();
    std::cout << "You've just entered room " << roomNumber();
    if (_is_blowed)
        std::cout << " and you have just been bombed";
    std::cout << "\n";

}

void RoomBomb::blow()
{
    _is_blowed = true;
    for (Direction d(North); d <= West; d = static_cast<Direction>(d+1))
        if (!getSide(d)->isDoor())
            setSide(d, new WallBlown);
}

std::string RoomBomb::to_string()
{
    std::stringstream out;
    out << "[RoomBomb: " << roomNumber() 
        << " blown: " << _is_blowed << " - ("
        << "N: " << getSide(North) << ", "
        << "S: " << getSide(South) << ", "
        << "E: " << getSide(East) << ", "
        << "W: " << getSide(West) 
        << ")]";
    return out.str();

    return Room::to_string();
}
