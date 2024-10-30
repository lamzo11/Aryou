#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include<iostream>
#include "Subject.h"

class EventManager : public Subject {
public:
    // Methods to simulate events
    void carArrived() {
        std::cout << "EventManager: Car arrival event triggered.\n";
        notifyObservers();  // Notify all observers of the car arrival
    }

    void employeeAbsent() {
        std::cout << "EventManager: Employee absence event triggered.\n";
        notifyObservers();  // Notify all observers of the employee absence
    }
};

#endif
