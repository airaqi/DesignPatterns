#ifndef __MAP_MAZE_FACTORY_PROTOTYPE_H__
#define __MAP_MAZE_FACTORY_PROTOTYPE_H__ 

#include "map_door.h"
#include "map_maze.h"
#include "map_maze_factory_abstract.h"
#include "map_room.h"
#include "map_wall.h"

class MazePrototypeFactory : public AbstractMazeFactory
{
    public:
        MazePrototypeFactory(Maze* = new Maze, Wall* = new Wall, Room* = new Room, Door* = new Door);
        virtual ~MazePrototypeFactory();

        virtual Maze * makeMaze() const override;
        virtual Room * makeRoom(int) override;
        virtual Wall * makeWall() const override;
        virtual Door * makeDoor(Room *, Room *) const override;

    private:
        virtual Room * fillWalls(Room *) override;

    private:
        Maze *_prototypeMaze;
        Room *_prototypeRoom;
        Wall *_prototypeWall;
        Door *_prototypeDoor;
};

#endif /* ifndef __MAP_MAZE_FACTORY_PROTOTYPE_H__ */
