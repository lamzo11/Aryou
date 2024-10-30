#include <iostream>
#include "../../includes/StrategyIncludes/Scheduler.h"
#include "../../includes/StrategyIncludes/ExperienceBasedAssignment.h"
#include "../../includes/StrategyIncludes/ContractTypeAssignment.h"
#include "../../includes/FactoryHeaders/EmployeeFactory.h"
#include "../../includes/FactoryHeaders/CarFactory.h"

int main() {
    // Create employees and cars
    Employee employee1 = EmployeeFactory::createEmployee(1, "Alice", true, 5);
    Employee employee2 = EmployeeFactory::createEmployee(2, "Bob", false, 2);
    std::vector<Employee> employees = { employee1, employee2 };

    Car car1 = CarFactory::createCar(1, 3, 5, 101);
    Car car2 = CarFactory::createCar(2, 6, 8, 102);
    std::vector<Car> cars = { car1, car2 };

    // Initialize Scheduler with ExperienceBasedAssignment strategy
    Scheduler scheduler(std::make_unique<ExperienceBasedAssignment>());
    std::cout << "Using Experience-Based Assignment:\n";
    scheduler.assignTasks(employees, cars);

    // Switch to ContractTypeAssignment strategy
    scheduler.setStrategy(std::make_unique<ContractTypeAssignment>());
    std::cout << "\nUsing Contract Type Assignment:\n";
    scheduler.assignTasks(employees, cars);

    return 0;
}
