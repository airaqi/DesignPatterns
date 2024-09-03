#ifndef __CHASSIS_H__
#define __CHASSIS_H__ 

#include "composite_equipment.h"

class Chassis : public CompositeEquipment
{
    public:
        Chassis(const char* name);
        Chassis(const char* name, double price, int power);
        virtual ~Chassis();

        virtual const std::string& getClassId() const;

        virtual void accept(EquipmentVisitor&);
};

#endif /* ifndef __CHASSIS_H__ */
