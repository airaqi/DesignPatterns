#ifndef __MAP_MAZE_FACTORY_ABSTRACT_H__
#define __MAP_MAZE_FACTORY_ABSTRACT_H__

#include "map_door.h"
#include "map_maze.h"
#include "map_wall.h"

class AbstractMazeFactory
{
    public:
        AbstractMazeFactory() {}
        virtual ~AbstractMazeFactory() {}

        virtual Maze* makeMaze() const = 0;
        virtual Wall* makeWall() const = 0;
        virtual Room* makeRoom(int) = 0;
        virtual Door* makeDoor(Room*, Room*) const = 0;

    private:
        virtual Room* fillWalls(Room*) = 0;
};

#endif /* __MAP_MAZE_FACTORY_ABSTRACT_H__ */
