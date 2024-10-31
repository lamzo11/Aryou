#include "../../includes/ClassIncludes/Team.h"
#include <algorithm>

Team::Team(int fieldId) : workFieldId(fieldId) {}

void Team::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void Team::removeEmployee(int employeeId) {
    employees.erase(std::remove_if(employees.begin(), employees.end(),
                                   [employeeId](const Employee &e) { return e.getId() == employeeId; }),
                    employees.end());
}

int Team::getTeamSize() const { return employees.size(); }
int Team::getWorkFieldId() const { return workFieldId; }
