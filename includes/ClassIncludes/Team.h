#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Employee.h"

class Team {
private:
    std::vector<Employee> employees;
    int workFieldId;

public:
    Team(int fieldId);

    void addEmployee(const Employee& employee);
    void removeEmployee(int employeeId);
    int getTeamSize() const;
    int getWorkFieldId() const;
};

#endif
