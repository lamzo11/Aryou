#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "TaskAssignmentStrategy.h"
#include "../ObserverIncludes/Observer.h"
#include "../ClassIncludes/Employee.h"
#include "../ClassIncludes/Car.h"
#include <memory>
#include <vector>
#include <queue>

class Scheduler : public Observer {
private:
    std::unique_ptr<TaskAssignmentStrategy> strategy;
    std::queue<Car> carQueue;
    std::vector<Employee> employees;

public:
    Scheduler(std::unique_ptr<TaskAssignmentStrategy> initialStrategy, const std::vector<Employee>& team)
        : strategy(std::move(initialStrategy)), employees(team) {}

    /*Set a new strategy for task assignment */
    void setStrategy(std::unique_ptr<TaskAssignmentStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    /* Queue a car for processing */
    void queueCar(const Car& car) {
        carQueue.push(car);
    }

    /* Process each car with the current strategy */
    void processCars() {
        while (!carQueue.empty()) {
            Car car = carQueue.front();
            carQueue.pop();
            
            /* Assign the car to an employee using the current strategy */
            for (Employee& employee : employees) {
                if (!employee.getIsOnBreak()) {
                    strategy->assignTask(employee, car);
                    break;  /* Move on to the next car once assigned */
                }
            }
        }
    }

    /* Override the update method to handle events (e.g., new car arrival) */
    void update() override {
        processCars();
    }
};

#endif
