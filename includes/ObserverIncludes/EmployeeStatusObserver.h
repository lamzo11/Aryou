#ifndef EMPLOYEESTATUSOBSERVER_H
#define EMPLOYEESTATUSOBSERVER_H

#include "Observer.h"
#include <iostream>

class EmployeeStatusObserver : public Observer {
public:
    void update() override {
        std::cout << "EmployeeStatusObserver: An employee status has changed.\n";
        // Additional logic for handling employee status update
    }
};

#endif
