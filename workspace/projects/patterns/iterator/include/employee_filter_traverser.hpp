#ifndef __EMPLOYEE_TRAVERSER_FILTERED_H__
#define __EMPLOYEE_TRAVERSER_FILTERED_H__ 

#include "employee.h"
#include "list.h"
#include "traversal_list_filtered.hpp"

class EmployeeFilteredTraverser : public FilteredListTraverser<Employee>
{
    public:
        EmployeeFilteredTraverser(List<Employee>* list);
        virtual ~EmployeeFilteredTraverser();

        bool processItem(const Employee&) override;
        bool testItem(const Employee&) override;

};
#endif /* ifndef __EMPLOYEE_TRAVERSER_FILTERED_H__ */
