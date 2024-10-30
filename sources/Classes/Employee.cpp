#include "../includes/ClassIncludes/Employee.h"

// Constructor
Employee::Employee(int id, const std::string& name, bool permanent, int experience)
    : id(id), name(name), isPermanent(permanent), isOnBreak(false), experienceLevel(experience) {}

// Getters
int Employee::getId() const { return id; }
const std::string& Employee::getName() const { return name; }
bool Employee::getIsPermanent() const { return isPermanent; }
bool Employee::getIsOnBreak() const { return isOnBreak; }
int Employee::getExperienceLevel() const { return experienceLevel; }

// Methods to manage break status
void Employee::startBreak() { isOnBreak = true; }
void Employee::endBreak() { isOnBreak = false; }
