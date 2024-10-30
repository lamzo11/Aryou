#ifndef EMPLOYEEFACTORY_H
#define EMPLOYEEFACTORY_H

#include "../ClassIncludes/Employee.h"
#include <string>

class EmployeeFactory {
public:
    // Static method to create an Employee instance
    static Employee createEmployee(int id, const std::string& name, bool isPermanent, int experienceLevel);
};

#endif
