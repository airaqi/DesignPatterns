#ifndef __MAP_MAZE_PLAYER_H__
#define __MAP_MAZE_PLAYER_H__ 

#include "map_maze.h"

class MazePlayer
{
    public:
        virtual void play(Maze* maze, const char* = nullptr);
};

#endif /* ifndef __MAP_MAZE_PLAYER_H__ */
