#ifndef __MAZE_FACTORY_BUILDER_STANDARD_H__
#define __MAZE_FACTORY_BUILDER_STANDARD_H__ 

#include "map_direction.h"
#include "maze_builder.hpp"

class MazeBuilderStandard : public MazeBuilder
{
    public:
        MazeBuilderStandard();
        virtual ~MazeBuilderStandard();

        virtual void buildMaze();
        virtual void buildRoom(int room = 0);
        virtual void buildDoor(int from, int to);
        virtual Maze* getMaze();
        virtual void resetMaze();

    private:
        Direction commonWall(Room*, Room*);
        
    private:
        Maze* _maze;
        int _next_room;
};

#endif /* ifndef __MAZE_FACTORY_BUILDER_STANDARD_H__ */
