#ifndef __MAZE_FACTORY_H__
#define __MAZE_FACTORY_H__

#include "map_door.h"
#include "map_maze.h"
#include "map_maze_factory_abstract.h"
#include "map_room.h"
#include "map_wall.h"

class MazeFactory : public AbstractMazeFactory {
public:
    static MazeFactory* instance();
    static void destroy();

    virtual ~MazeFactory();

    virtual Maze* makeMaze() const;
    virtual Wall* makeWall() const;
    virtual Room* makeRoom(int);
    virtual Door* makeDoor(Room*, Room*) const;

protected:
    MazeFactory();

private:
    static MazeFactory* _instance;
    virtual Room* fillWalls(Room*);
};

#endif /* ifndef __MAZE_FACTORY_H__ */
