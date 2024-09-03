#include "equipment_inventory.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>


Inventory::Inventory() {}

Inventory::~Inventory() {}

void Inventory::accumulate(const std::string name)
{
    if (_inventory.find(name) != _inventory.end())
        _inventory[name] += 1;
    else
        _inventory[name] = 1;
}

double Inventory::get(const std::string name)
{
    if (_inventory.find(name) != _inventory.end())
        return _inventory[name];
    else
        return 0;
}

std::pmr::unordered_map<std::string, double>& Inventory::getInventory()
{
    return _inventory;
}


std::string Inventory::to_string(std::string prefix)
{
    std::stringstream sout;
    for (auto const& x : _inventory)
        sout << prefix << x.first << ": " << x.second << std::endl;
    return sout.str();
}

std::ostream& operator<<(std::ostream& cout, Inventory& that)
{
    cout << that.to_string("\t");
    return cout;
}
