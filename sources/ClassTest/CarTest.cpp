#include <iostream>
#include "../includes/ClassIncludes/Car.h"


void testCarClass() {
    // Create a Car instance with id = 1, cleanlinessLevel = 4, fuelLevel = 6, rentalCompanyId = 101
    Car car(1, 4, 6, 101);

    // Check if the getters return the expected values
    std::cout << "Testing Car class...\n";

    if (car.getId() == 1) {
        std::cout << "ID Test Passed\n";
    } else {
        std::cout << "ID Test Failed\n";
    }

    if (car.getCleanlinessLevel() == 4) {
        std::cout << "Cleanliness Level Test Passed\n";
    } else {
        std::cout << "Cleanliness Level Test Failed\n";
    }

    if (car.getFuelLevel() == 6) {
        std::cout << "Fuel Level Test Passed\n";
    } else {
        std::cout << "Fuel Level Test Failed\n";
    }

    if (car.getRentalCompanyId() == 101) {
        std::cout << "Rental Company ID Test Passed\n";
    } else {
        std::cout << "Rental Company ID Test Failed\n";
    }
}

int main() {
    testCarClass();
    return 0;
}
