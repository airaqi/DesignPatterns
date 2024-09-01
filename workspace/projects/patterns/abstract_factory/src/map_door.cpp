#include "map_door.h"
#include <iostream>
#include <sstream>
#include <string>

Door::Door(Room* room1, Room* room2, bool isOpen) : 
    _room1(room1), _room2(room2), _isOpen(isOpen), _isMarked(false) {}

Door::Door(const Door *that)
{
    _isOpen = that->_isOpen;
    _isMarked = that->_isMarked;
    _room1 = nullptr;
    _room2 = nullptr;
}

Door::~Door() {}

// Part of prototype pattern implementation
Door* Door::clone()
{
    return new Door(*this);
}

void Door::initialize(Room *r1, Room *r2)
{
    _room1 = r1;
    _room2 = r2;
}

void Door::enter()
{
    std::cout << "You've just entered door\n";
}

Room* Door::otherSideFrom(Room* room)
{
    if (room == _room1) return _room2;
    else if (room == _room2) return _room1;
    else return nullptr;
}

bool Door::isDoor() const { return true; }

std::string Door::to_string()
{
    std::stringstream out;
    out << "[Door" << "(" << _room1->roomNumber() << ", " << _room2->roomNumber() << ")" << "]";
    return out.str();
}

void Door::mark() { _isMarked = true; }

bool Door::marked() { return _isMarked; }
