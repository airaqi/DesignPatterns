#ifndef __LEAF_EQUIPMENT_H__
#define __LEAF_EQUIPMENT_H__

#include "equipment.h"
#include <string>

class LeafEquipment : public Equipment {
public:
    virtual ~LeafEquipment() {}

    virtual bool isLeaf();

    virtual Watt power();
    virtual Currency netPrice();
    virtual Currency discountPrice(double discount);

    virtual void add(Equipment*);
    virtual void remove(Equipment*);
    virtual Iterator<Equipment*>* createIterator();

    virtual std::string to_string(std::string = "");

protected:
    LeafEquipment(const char* name)
        : Equipment(name) {}
    LeafEquipment(const char* name, double price, int power)
        : Equipment(name, price, power) {}
};

#endif /* ifndef __LEAF_EQUIPMENT_H__ */
