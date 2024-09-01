#include "map_maze_factory_magic.h"
#include "map_room_bomb.h"
#include "map_wall.h"

BombMazeFactory::BombMazeFactory() { }

BombMazeFactory::~BombMazeFactory() { }

BombMazeFactory* BombMazeFactory::_instance = nullptr;

BombMazeFactory* BombMazeFactory::instance()
{
    if (_instance == nullptr)
        _instance = new BombMazeFactory();
    return _instance;
}

void BombMazeFactory::destroy()
{
    if (_instance)
        delete _instance;
    _instance = nullptr;
}

Room* BombMazeFactory::makeRoom(int roomNo)
{
    return fillWalls(new RoomBomb(roomNo));
}

Maze* BombMazeFactory::makeMaze() const
{
    return new Maze();
}

Wall* BombMazeFactory::makeWall() const
{
    return new Wall;
}

Door* BombMazeFactory::makeDoor(Room* room1, Room* room2) const
{
    return new Door(room1, room2);
}

Room* BombMazeFactory::fillWalls(Room* room)
{
    for (Direction d(North); d <= West; d = static_cast<Direction>(d + 1))
        room->setSide(d, makeWall());
    return room;
}
