#ifndef __MAZE_FACTORY_BUILDER_H__
#define __MAZE_FACTORY_BUILDER_H__ 

#include "map_maze.h"

class MazeBuilder
{
    public:
        virtual ~MazeBuilder() {}

        virtual void buildMaze() {}
        virtual void buildRoom(int room) {}
        virtual void buildDoor(int from, int to) {}

        virtual Maze* getMaze() { return 0; }

    protected:
        MazeBuilder() {}
};

#endif /* ifndef __MAZE_FACTORY_BUILDER_H__ */
