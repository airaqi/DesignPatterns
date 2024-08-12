#ifndef __MAP_WALL_BLOWN_H__
#define __MAP_WALL_BLOWN_H__ 

#include "map_wall.h"

class WallBlown : public Wall
{
    public:
        WallBlown();
        virtual ~WallBlown();

        virtual void blow();
        virtual void enter() override;
        virtual std::string to_string() override;

    private:
        bool _is_blown;
};

#endif /* ifndef __MAP_WALL_BLOWN_H__ */
