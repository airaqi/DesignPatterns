#ifndef __MAZE_FACTORY_MAGIC_H__
#define __MAZE_FACTORY_MAGIC_H__ 

#include "map_maze_factory_abstract.h"
#include "map_room.h"

class BombMazeFactory : public AbstractMazeFactory
{
    public:
        BombMazeFactory();
        virtual ~BombMazeFactory();

        virtual Room* makeRoom(int) override;
        virtual Maze* makeMaze() const override;
        virtual Wall* makeWall() const override;
        virtual Door* makeDoor(Room*, Room*) const override;

    private:
        virtual Room* fillWalls(Room* room) override;
};

#endif /* ifndef __MAZE_FACTORY_MAGIC_H__ */
