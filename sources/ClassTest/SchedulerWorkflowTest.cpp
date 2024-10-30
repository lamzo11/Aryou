#include <iostream>
#include "../../includes/StrategyIncludes/Scheduler.h"
#include "../../includes/ObserverIncludes/EventManager.h"
#include "../../includes/StrategyIncludes/ExperienceBasedAssignment.h"
#include "../../includes/StrategyIncludes/ContractTypeAssignment.h"
#include "../../includes/FactoryHeaders/EmployeeFactory.h"
#include "../../includes/FactoryHeaders/CarFactory.h"
#include "../../includes/ObserverIncludes/CarArrivalObserver.h"

int main() {
    // Create employees and a Scheduler with an initial strategy
    Employee emp1 = EmployeeFactory::createEmployee(1, "Alice", true, 5);
    Employee emp2 = EmployeeFactory::createEmployee(2, "Bob", false, 2);
    std::vector<Employee> employees = { emp1, emp2 };

    Scheduler scheduler(std::make_unique<ExperienceBasedAssignment>(), employees);

    // Create cars and add them to the scheduler's car queue
    Car car1 = CarFactory::createCar(1, 3, 5, 101);
    Car car2 = CarFactory::createCar(2, 6, 8, 102);
    scheduler.queueCar(car1);
    scheduler.queueCar(car2);

    // Create an EventManager and register the scheduler as an observer
    EventManager eventManager;
    eventManager.addObserver(&scheduler);

    // Simulate car arrival event (triggering task assignment)
    std::cout << "--- Initial Task Assignment (Experience-Based) ---\n";
    eventManager.carArrived();  // Notifies the scheduler to process cars

    // Switch strategy and reprocess with a new event
    scheduler.setStrategy(std::make_unique<ContractTypeAssignment>());
    std::cout << "\n--- Reassign Tasks with Contract-Type Strategy ---\n";
    eventManager.carArrived();  // Notifies the scheduler to process with the new strategy

    return 0;
}
