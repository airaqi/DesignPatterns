#ifndef __LEAF_EQUIPMENT_H__
#define __LEAF_EQUIPMENT_H__

#include "equipment.h"
#include "equipment_visitor.hpp"
#include <string>

class LeafEquipment : public Equipment {
public:
    virtual ~LeafEquipment();

    virtual const std::string& getClassId() const;

    virtual bool isLeaf();

    virtual Watt power();
    virtual Currency netPrice();
    virtual Currency discountPrice(double discount);

    virtual void add(Equipment*);
    virtual void remove(Equipment*);
    virtual Iterator<Equipment*>* createIterator();

    virtual void accept(EquipmentVisitor&);

    virtual std::string to_string(std::string = "");

protected:
    LeafEquipment(const char* name);
    LeafEquipment(const char* name, double price, int power);
};

#endif /* ifndef __LEAF_EQUIPMENT_H__ */
