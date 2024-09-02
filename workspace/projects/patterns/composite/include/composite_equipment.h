#ifndef __COMPOSITE_EQUIPMENT_H__
#define __COMPOSITE_EQUIPMENT_H__ 

/*! \class CompositeEquipment : public Eq
 *  \brief Brief class description
 *
 *  Detailed description
 */
#include "currency.h"
#include "equipment.h"
#include "iterator.h"
#include "list.h"
#include "watt.h"
#include <string>

class CompositeEquipment : public Equipment
{
public:
    virtual ~CompositeEquipment();

    virtual bool isComposite() { return true; }

    virtual Watt power();
    virtual Currency netPrice();
    virtual Currency discountPrice(double);

    virtual void add(Equipment*);
    virtual void remove(Equipment*);
    virtual Iterator<Equipment*>* createIterator();

    virtual std::string to_string(std::string = "");

protected:
    CompositeEquipment(const char* name);
    CompositeEquipment(const char* name, double price, int power);
private:
    List<Equipment*>* _children;
};  

#endif /* ifndef __COMPOSITE_EQUIPMENT_H__ */
