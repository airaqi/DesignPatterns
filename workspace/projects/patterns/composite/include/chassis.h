#ifndef __CHASSIS_H__
#define __CHASSIS_H__ 

#include "composite_equipment.h"

class Chassis : public CompositeEquipment
{
    public:
        Chassis(const char* name) : CompositeEquipment(name) {}
        Chassis(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
        virtual ~Chassis() {}
};

#endif /* ifndef __CHASSIS_H__ */
