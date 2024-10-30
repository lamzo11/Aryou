#include "../../includes/FactoryHeaders/TeamFactory.h"

// Implementation of createTeam method
Team TeamFactory::createTeam(int workFieldId) {
    return Team(workFieldId);
}

// Implementation of addEmployeeToTeam method
void TeamFactory::addEmployeeToTeam(Team& team, const Employee& employee) {
    team.addEmployee(employee);
}
