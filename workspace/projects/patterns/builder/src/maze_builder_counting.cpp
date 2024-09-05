#include "maze_builder_counting.hpp"

MazeBuilderCouting::MazeBuilderCouting() : _doors(0), _rooms(0) {}
MazeBuilderCouting::~MazeBuilderCouting() {}

void MazeBuilderCouting::buildMaze()
{
    _doors = 0;
    _rooms = 0;
}

void MazeBuilderCouting::buildRoom(int room)
{
    _rooms++;
}

void MazeBuilderCouting::buildDoor(int from, int to)
{
    _doors++;
}

void MazeBuilderCouting::getCount(int& doors, int& rooms) const
{
    doors = _doors;
    rooms = _rooms;
}

void MazeBuilderCouting::reset()
{
    _doors = 0;
    _rooms = 0;
}

int MazeBuilderCouting::getRooms() const
{
    return _rooms;
}

int MazeBuilderCouting::getDoors() const
{
    return _doors;
}
