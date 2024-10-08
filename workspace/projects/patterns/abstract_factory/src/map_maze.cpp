#include "map_maze.h"
#include <ostream>
#include <sstream>
#include <string>

Maze::Maze() : _start(0), _target(0), _current(0) {}

Maze::~Maze()
{
    for (auto it : _rooms)
    {
        delete it.second;
    }
    _rooms.clear();
}

Maze::Maze(const Maze* that)
{
    _start = that->_start;
    _target = that->_target;
    _current = that->_current;
       
    for (auto it : that->_rooms)
        _rooms.insert_or_assign(it.first, it.second);
}

Maze* Maze::clone()
{
    return new Maze(*this);
}

void Maze::addRoom(Room* room) 
{
    _rooms.insert_or_assign(room->roomNumber(), room);
    if (_rooms.size() == 1) _start = room->roomNumber();
}

Room* Maze::roomNo(int roomNo) const
{
    if (_rooms.find(roomNo) != _rooms.end())
        return _rooms.at(roomNo);
    return nullptr;
}

bool Maze::isTarget(Room* room) const
{
    return (_target == room->roomNumber());
}

void Maze::addStart(Room* room)
{
    _start = room->roomNumber();
    addRoom(room);
}

void Maze::addTarget(Room* room)
{
    _target = room->roomNumber();
    addRoom(room);
}

std::string Maze::to_string() const
{
    std::stringstream out;
    out << "[Maze : start: " << start() << " end: " << target() << "\n"; 
    for (auto it : _rooms)
        out << "\t" << it.second << "\n";
    out << "\t]";
    return out.str();

}

std::ostream& operator<<(std::ostream& out, Maze* maze)
{
   out << maze->to_string();
   return out;
}
