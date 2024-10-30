#include "../../includes/ObserverIncludes/EventManager.h"
#include "../../includes/ObserverIncludes/CarArrivalObserver.h"
#include "../../includes/ObserverIncludes/EmployeeStatusObserver.h"

int main() {
    // Create an event manager (Subject)
    EventManager eventManager;

    // Create observers
    CarArrivalObserver carObserver;
    EmployeeStatusObserver employeeObserver;

    // Register observers with the event manager
    eventManager.addObserver(&carObserver);
    eventManager.addObserver(&employeeObserver);

    // Simulate events
    std::cout << "\n--- Car Arrival Event ---\n";
    eventManager.carArrived();  // Notify observers of car arrival

    std::cout << "\n--- Employee Absence Event ---\n";
    eventManager.employeeAbsent();  // Notify observers of employee absence

    return 0;
}
