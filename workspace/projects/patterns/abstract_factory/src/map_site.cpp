#include "map_site.h"
#include <ostream>

std::ostream& operator<<(std::ostream& out, MapSite* site)
{
    out << site->to_string();

    return out;
}
