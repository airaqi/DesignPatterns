#include "map_maze_factory_prototype.hpp"

MazePrototypeFactory::MazePrototypeFactory(Maze *maze, Wall *wall, Room *room, Door *door) :
    _prototypeMaze(maze), _prototypeWall(wall), _prototypeRoom(room), _prototypeDoor(door) {}

MazePrototypeFactory::~MazePrototypeFactory() 
{
    delete _prototypeMaze;
    delete _prototypeDoor;
    delete _prototypeRoom;
    delete _prototypeWall;
}

Wall* MazePrototypeFactory::makeWall() const
{
    return _prototypeWall->clone();
}

Door* MazePrototypeFactory::makeDoor(Room *r1, Room *r2) const
{
    Door *door = _prototypeDoor->clone();
    door->initialize(r1, r2);
    return door;
}

Room* MazePrototypeFactory::makeRoom(int num) 
{
    Room *room = fillWalls(_prototypeRoom->clone());
    room->initialize(num);
    return room;
}

Maze* MazePrototypeFactory::makeMaze() const
{
    return _prototypeMaze->clone();
}

Room* MazePrototypeFactory::fillWalls(Room *room)
{
    for (Direction d(North); d <= West; d = static_cast<Direction>(d+1))
        room->setSide(d, makeWall());
    return room;
}

