#ifndef EXPERIENCEBASEDASSIGNMENT_H
#define EXPERIENCEBASEDASSIGNMENT_H
#include<iostream>
#include "TaskAssignmentStrategy.h"

class ExperienceBasedAssignment : public TaskAssignmentStrategy {
public:
    void assignTask(Employee& employee, Car& car) override {
        // Implement assignment logic based on employee experience
        if (employee.getExperienceLevel() > 3) {
            std::cout << "Assigning high-priority task to experienced employee: " << employee.getName() << std::endl;
        } else {
            std::cout << "Assigning standard task to less experienced employee: " << employee.getName() << std::endl;
        }
    }
};

#endif
