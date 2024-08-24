#include "employees_print.hpp"
#include <iostream>


PrintEmployees::PrintEmployees(List<Employee>* list, int n) 
    : ListTraverser<Employee>(list), _total(n), _count(0) {}


bool PrintEmployees::processItem(const Employee& e)
{
    std::cout << e.name() << "\n";
    _count++;
    return _count < _total;
}


