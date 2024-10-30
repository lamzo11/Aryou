#ifndef CONTRACTTYPEASSIGNMENT_H
#define CONTRACTTYPEASSIGNMENT_H
#include<iostream>
#include "TaskAssignmentStrategy.h"

class ContractTypeAssignment : public TaskAssignmentStrategy {
public:
    void assignTask(Employee& employee, Car& car) override {
        // Implement assignment logic based on contract type
        if (employee.getIsPermanent()) {
            std::cout << "Assigning critical task to permanent employee: " << employee.getName() << std::endl;
        } else {
            std::cout << "Assigning flexible task to temporary employee: " << employee.getName() << std::endl;
        }
    }
};

#endif
