#ifndef __MAP_SITE_H__
#define __MAP_SITE_H__ 

#include <ostream>
#include <string>
class MapSite
{
    public:
        MapSite() {}
        virtual ~MapSite() {}

        // Part of prototype pattern implementation
        virtual MapSite* clone() = 0;

        virtual void enter() = 0;
        virtual bool isDoor() const { return false; };

        virtual void mark() {}
        virtual bool marked() { return false; }

        virtual std::string to_string() = 0;

        friend std::ostream& operator<<(std::ostream&, MapSite*);
};

#endif /* ifndef __MAP_SITE_H__ */
