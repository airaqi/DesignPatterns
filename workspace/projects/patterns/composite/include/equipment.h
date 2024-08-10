#ifndef __EQUIPMENT_H__
#define __EQUIPMENT_H__

#include "iterator.h"
#include "currency.h"
#include "watt.h"
#include <string>

class Equipment 
{
    public:
        virtual ~Equipment() {}

        virtual const char* name() { return _name; }

        virtual void set_price(double price) { _price = Currency(price); }
        virtual void set_power(int power) { _power = Watt(power); }

        virtual Watt power() = 0;
        virtual Currency netPrice() = 0;
        virtual Currency discountPrice(double discount) = 0;

        virtual void add(Equipment*) = 0;
        virtual void remove(Equipment*) = 0;
        virtual Iterator<Equipment*>* createIterator() = 0;

        virtual bool isComposite() { return false; }
        virtual bool isLeaf() { return false; }

        virtual std::string to_string() = 0;

    protected:
        Equipment(const char* name);
        Equipment(const char* name, double price, int power);

    private:
        const char* _name;

    protected:
        Watt _power;
        Currency _price;
};

#endif /* ifndef  */

