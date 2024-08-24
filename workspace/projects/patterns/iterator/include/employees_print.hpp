#ifndef __EMPLOYEE_PRINT_H__
#define __EMPLOYEE_PRINT_H__ 

#include "employee.h"
#include "list.h"
#include "traversal_list.hpp"
class PrintEmployees : public ListTraverser<Employee>
{
    public:
        PrintEmployees(List<Employee>* list, int n);

    protected:
       virtual bool processItem(const Employee&); 

    private:
       int _total;
       int _count;
};

#endif /* ifndef __EMPLOYEE_PRINT_H__ */
