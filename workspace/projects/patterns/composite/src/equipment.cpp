#include "equipment.h"
#include "currency.h"
#include "watt.h"


Equipment::Equipment(const char* name) : Equipment(name, 0, 0) {}
Equipment::Equipment(const char* name, double price, int power) : _name(name), _price(price), _power(power) {}


