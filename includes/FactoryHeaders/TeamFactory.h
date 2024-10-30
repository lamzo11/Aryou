#ifndef TEAMFACTORY_H
#define TEAMFACTORY_H

#include "../ClassIncludes/Team.h"
#include "../ClassIncludes/Employee.h"

class TeamFactory {
public:
    // Static method to create a Team instance
    static Team createTeam(int workFieldId);

    // Method to add an employee to a team
    static void addEmployeeToTeam(Team& team, const Employee& employee);
};

#endif
