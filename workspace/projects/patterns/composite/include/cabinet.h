#ifndef __CABINET_H__
#define __CABINET_H__ 

#include "composite_equipment.h"

class Cabinet : public CompositeEquipment
{
    public:
        Cabinet(const char* name) : CompositeEquipment(name) {}
        Cabinet(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
        virtual ~Cabinet() {}
};

#endif /* ifndef __CABINET_H__ */
