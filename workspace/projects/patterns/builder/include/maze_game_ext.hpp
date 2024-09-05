#ifndef __MAZE_GAME_EXTENDED_H__
#define __MAZE_GAME_EXTENDED_H__ 

#include "map_maze.h"
#include "map_maze_game.h"
#include "maze_builder.hpp"

class MazeGameExt : public MazeGame
{
    public:
        MazeGameExt();
        virtual ~MazeGameExt();

        virtual Maze* createMaze(MazeBuilder&);
        virtual Maze* createComplexMaze(MazeBuilder&, int);
};

#endif /* ifndef __MAZE_GAME_EXTENDED_H__ */
