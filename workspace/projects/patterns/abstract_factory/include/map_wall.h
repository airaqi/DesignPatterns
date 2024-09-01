#ifndef __MAP_WALL_H__
#define __MAP_WALL_H__ 

#include "map_site.h"

class Wall : public MapSite
{
    public:
        Wall();
        virtual ~Wall();

        // Part of prototype pattern implementation
        virtual Wall* clone() override;

        void enter() override;
        virtual std::string to_string() override;
};

#endif /* ifndef __MAP_WALL_H__ */
