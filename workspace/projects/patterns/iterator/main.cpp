#include "employee.h"
#include "employee_filter_traverser.hpp"
#include "employees_print.hpp"
#include "iterator.h"
#include "iterator_ptr.hpp"
#include "list.h"
#include "list_iterator.h"
#include "list_iterator_reverse.h"
#include "traversal_list_filtered.hpp"
#include "traversal_list.hpp"
#include <iostream>

void printEmployees(Iterator<Employee>& i)
{
    for (i.first(); !i.is_done(); i.next())
        std::cout << i.currentItem().name() << "\n";
}

bool printEmployeesFiltered(const Employee& e)
{
    if (e.name()[0] == 'S')
    {
        std::cout << e.name() << "\n";
    }
    return true;
}

bool print(const Employee& e)
{
    std::cout << e.name() << "\n";
    return true;
}

int main(int argc, char *argv[])
{
    List<Employee> employees;

    employees.append(Employee("First"));
    employees.append(Employee("Second"));
    employees.append(Employee("Third"));
    employees.append(Employee("Fourth"));
    employees.append(Employee("Fifth"));
    employees.append(Employee("Sixth"));
    employees.append(Employee("Seventh"));


    std::cout << "Forward iterator: " << "\n";
    Iterator<Employee>* i = new ListIterator<Employee>(&employees);
    printEmployees(*i);
    delete i;
    
    std::cout << "Reverse iterator: " << "\n";
    Iterator<Employee>* r = new ReverseListIterator<Employee>(&employees);
    printEmployees(*r);
    delete r;

    std::cout << "Iterator Pointer: \n";
    Iterator<Employee>* ii = new ListIterator<Employee>(&employees);
    IteratorPtr<Employee> pii(ii);
    printEmployees(pii);

    std::cout << "List traverser: \n";
    ListTraverser<Employee> traverer(&employees);
    traverer.traverse(print);

    std::cout << "Employee Print Traversal: \n";
    PrintEmployees *peptr, pe(&employees, 5);
    peptr = &pe;
    peptr->traverse();


    std::cout << "List filtered traversal: \n";
    ListTraverser<Employee> t1(&employees);
    t1.traverse(printEmployeesFiltered);

    std::cout << "FilteredListTraverser: \n";
    EmployeeFilteredTraverser ft(&employees);
    ft.traverse();

    return 0;
}
