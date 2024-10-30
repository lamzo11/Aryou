#include "../../includes/FactoryHeaders/EmployeeFactory.h"

// Implementation of the createEmployee method
Employee EmployeeFactory::createEmployee(int id, const std::string& name, bool isPermanent, int experienceLevel) {
    return Employee(id, name, isPermanent, experienceLevel);
}
