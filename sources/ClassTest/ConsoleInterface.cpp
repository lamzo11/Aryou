#include <iostream>
#include <memory>
#include <vector>
#include "../../includes/StrategyIncludes/Scheduler.h"
#include "../../includes/ObserverIncludes/EventManager.h"
#include "../../includes/StrategyIncludes/ExperienceBasedAssignment.h"
#include "../../includes/StrategyIncludes/ContractTypeAssignment.h"
#include "../../includes/FactoryHeaders/EmployeeFactory.h"
#include "../../includes/FactoryHeaders/CarFactory.h"

void displayMenu() {
    std::cout << "\n--- Car Rental Management Tool ---\n";
    std::cout << "1. Add Car to Queue\n";
    std::cout << "2. Add Employee\n";
    std::cout << "3. Set Strategy: Experience-Based Assignment\n";
    std::cout << "4. Set Strategy: Contract-Type Assignment\n";
    std::cout << "5. Trigger Car Arrival Event\n";
    std::cout << "6. Set Employee on Break\n";
    std::cout << "7. Process All Cars\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    // Initialize components
    std::vector<Employee> employees;
    Scheduler scheduler(std::make_unique<ExperienceBasedAssignment>(), employees);
    EventManager eventManager;
    eventManager.addObserver(&scheduler);  // Register scheduler to be notified of events

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Car
                int id, cleanlinessLevel, fuelLevel, rentalCompanyId;
                std::cout << "Enter Car ID: "; std::cin >> id;
                std::cout << "Enter Cleanliness Level (1-6): "; std::cin >> cleanlinessLevel;
                std::cout << "Enter Fuel Level (0-8): "; std::cin >> fuelLevel;
                std::cout << "Enter Rental Company ID: "; std::cin >> rentalCompanyId;

                Car newCar = CarFactory::createCar(id, cleanlinessLevel, fuelLevel, rentalCompanyId);
                scheduler.queueCar(newCar);
                std::cout << "Car " << id << " added to queue.\n";
                break;
            }
            case 2: {
                // Add Employee
                int id, experienceLevel;
                std::string name;
                bool isPermanent;
                std::cout << "Enter Employee ID: "; std::cin >> id;
                std::cout << "Enter Name: "; std::cin >> name;
                std::cout << "Is Permanent? (1 for Yes, 0 for No): "; std::cin >> isPermanent;
                std::cout << "Enter Experience Level (1-5): "; std::cin >> experienceLevel;

                Employee newEmployee = EmployeeFactory::createEmployee(id, name, isPermanent, experienceLevel);
                employees.push_back(newEmployee);
                std::cout << "Employee " << name << " added.\n";
                break;
            }
            case 3: {
                // Set Experience-Based Strategy
                scheduler.setStrategy(std::make_unique<ExperienceBasedAssignment>());
                std::cout << "Set to Experience-Based Assignment Strategy.\n";
                break;
            }
            case 4: {
                // Set Contract-Type Strategy
                scheduler.setStrategy(std::make_unique<ContractTypeAssignment>());
                std::cout << "Set to Contract-Type Assignment Strategy.\n";
                break;
            }
            case 5: {
                // Trigger Car Arrival Event
                std::cout << "Car Arrival Event Triggered.\n";
                eventManager.carArrived();
                break;
            }
            case 6: {
                // Set Employee on Break
                int empId;
                std::cout << "Enter Employee ID to put on break: "; std::cin >> empId;
                
                auto it = std::find_if(employees.begin(), employees.end(), [empId](Employee& emp) {
                    return emp.getId() == empId;
                });
                
                if (it != employees.end()) {
                    it->startBreak();
                    std::cout << "Employee " << it->getName() << " is now on break.\n";
                } else {
                    std::cout << "Employee ID not found.\n";
                }
                break;
            }
            case 7: {
                // Process all cars in the queue
                std::cout << "Processing all cars in queue...\n";
                scheduler.processCars();
                break;
            }
            case 0:
                running = false;
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
                break;
        }
    }

    return 0;
}
