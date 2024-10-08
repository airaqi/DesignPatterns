#include "maze_factory.h"
#include "map_direction.h"
#include "map_maze.h"
#include "map_room.h"

MazeFactory::MazeFactory() { }

MazeFactory::~MazeFactory() { }


MazeFactory* MazeFactory::_instance = nullptr;

MazeFactory* MazeFactory::instance()
{
    if (_instance == nullptr)
        _instance = new MazeFactory();
    return _instance;
}

void MazeFactory::destroy()
{
    if (_instance)
        delete _instance;
    _instance = nullptr;
}

Maze* MazeFactory::makeMaze() const
{
    return new Maze();
}

Room* MazeFactory::makeRoom(int roomNo) 
{
    return fillWalls(new Room(roomNo));
}

Wall* MazeFactory::makeWall() const
{
    return new Wall;
}

Door* MazeFactory::makeDoor(Room* room1, Room* room2) const
{
    return new Door(room1, room2);
}

Room* MazeFactory::fillWalls(Room* room)
{
    for (Direction d(North); d <= West; d = static_cast<Direction>(d+1))
        room->setSide(d, makeWall());
    return room;
}
