#include "map_maze_game.h"
#include "map_direction.h"
#include "map_door.h"
#include "map_maze.h"
#include "map_maze_factory_abstract.h"

MazeGame::MazeGame() { }

Maze* MazeGame::createMaze()
{
    Maze* aMaze = new Maze();

    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Room* r3 = new Room(3);

    Door* d1 = new Door(r1, r2);
    Door* d2 = new Door(r2, r3);

    aMaze->addRoom(r1);
    aMaze->addRoom(r2);
    aMaze->addTarget(r3);

    r1->setSide(East, d1);
    r2->setSide(West, d1);

    r2->setSide(South, d2);
    r3->setSide(North, d2);

    r1->setSide(North, new Wall);
    r1->setSide(South, new Wall);
    r1->setSide(West, new Wall);

    r2->setSide(North, new Wall);
    r2->setSide(East, new Wall);

    r3->setSide(South, new Wall);
    r3->setSide(East, new Wall);
    r3->setSide(West, new Wall);

    return aMaze;
}

Maze* MazeGame::createMaze(AbstractMazeFactory& factory)
{
    Maze* maze = factory.makeMaze();

    Room* r1 = factory.makeRoom(1);
    Room* r2 = factory.makeRoom(2);
    Room* r3 = factory.makeRoom(3);
    Room* r4 = factory.makeRoom(4);

    Door* d1 = factory.makeDoor(r1, r2);
    Door* d2 = factory.makeDoor(r2, r3);
    Door* d3 = factory.makeDoor(r3, r4);

    maze->addRoom(r1);
    maze->addRoom(r2);
    maze->addRoom(r3);
    maze->addTarget(r4);

    r1->setSide(East, d1);
    r2->setSide(West, d1);
    r2->setSide(South, d2);
    r3->setSide(North, d2);
    r3->setSide(East, d3);
    r4->setSide(East, d3);

    return maze;
}
