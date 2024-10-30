#ifndef TASKASSIGNMENTSTRATEGY_H
#define TASKASSIGNMENTSTRATEGY_H

#include "../ClassIncludes/Employee.h"
#include "../ClassIncludes/Car.h"

class TaskAssignmentStrategy {
public:
    virtual ~TaskAssignmentStrategy() = default;
    virtual void assignTask(Employee& employee, Car& car) = 0;  // Pure virtual function
};

#endif
