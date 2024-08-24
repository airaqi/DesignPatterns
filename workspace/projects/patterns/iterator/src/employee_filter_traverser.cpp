#include "employee_filter_traverser.hpp"
#include "employee.h"
#include "list.h"
#include <iostream>

EmployeeFilteredTraverser::EmployeeFilteredTraverser(List<Employee>* list) : FilteredListTraverser<Employee>(list) {}

EmployeeFilteredTraverser::~EmployeeFilteredTraverser() {}

bool EmployeeFilteredTraverser::testItem(const Employee& e)
{
    return (e.name()[0] == 'S');
}

bool EmployeeFilteredTraverser::processItem(const Employee& e)
{
    std::cout << e.name() << "\n";
    return true;
}


