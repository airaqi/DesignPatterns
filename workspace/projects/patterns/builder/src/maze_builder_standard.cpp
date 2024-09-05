#include "maze_builder_standard.hpp"
#include "map_direction.h"
#include "map_door.h"
#include "map_maze.h"
#include "map_room.h"
#include "map_wall.h"
#include <cstdlib>

MazeBuilderStandard::MazeBuilderStandard() : _maze(0), _next_room(1) {}
MazeBuilderStandard::~MazeBuilderStandard() 
{
    resetMaze();
}

void MazeBuilderStandard::buildMaze() { _maze = new Maze; }
Maze* MazeBuilderStandard::getMaze() { return _maze; }
void MazeBuilderStandard::resetMaze() { delete _maze; }

void MazeBuilderStandard::buildRoom(int roomNo) 
{
    // use default next room number
    if (!roomNo) 
        roomNo = _next_room;

    if (!_maze->roomNo(roomNo))
    {
        Room* room = new Room(roomNo);
        if (roomNo == 1) _maze->addStart(room);
        _maze->addTarget(room);

        room->setSide(North, new Wall);
        room->setSide(South, new Wall);
        room->setSide(East, new Wall);
        room->setSide(West, new Wall);
        
        _next_room = roomNo + 1;
        room = nullptr;
    }
}

void MazeBuilderStandard::buildDoor(int from, int to) 
{
    Room* r1 = _maze->roomNo(from);
    Room* r2 = _maze->roomNo(to);
    Door* door = new Door(r1, r2);

    r1->setSide(commonWall(r1, r2), door);
    r2->setSide(commonWall(r2, r1), door);
}

Direction MazeBuilderStandard::commonWall(Room* r1, Room* r2)
{
    // solution is based on 
    // https://github.com/BartVandewoestyne/Design-Patterns-GoF/blob/master/Creational_Patterns/Builder/StandardMazeBuilder.cpp
    // TODO find a better solution, which should be in the maze.
    if (r1->roomNumber() < r2->roomNumber())
        return East;
    else 
        return West;
}

