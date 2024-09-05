#ifndef __MAZE_FACTORY_BUILDER_COUNTING_H__
#define __MAZE_FACTORY_BUILDER_COUNTING_H__ 

#include "maze_builder.hpp"

class MazeBuilderCouting : public MazeBuilder
{
    public:
        MazeBuilderCouting();
        virtual ~MazeBuilderCouting();

        virtual void buildMaze();
        virtual void buildRoom(int room = 0);
        virtual void buildDoor(int from, int to);

        void getCount(int&, int&) const;
        void reset();
        int getRooms() const;
        int getDoors() const;

    private:
        int _doors;
        int _rooms;
};

#endif /* ifndef __MAZE_FACTORY_BUILDER_COUNTING_H__ */
