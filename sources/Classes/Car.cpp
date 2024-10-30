#include "../includes/ClassIncludes/Car.h"

Car::Car(int id, int cleanliness, int fuel, int companyId)
    : id(id), cleanlinessLevel(cleanliness), fuelLevel(fuel), rentalCompanyId(companyId) {}

int Car::getId() const { return id; }
int Car::getCleanlinessLevel() const { return cleanlinessLevel; }
int Car::getFuelLevel() const { return fuelLevel; }
int Car::getRentalCompanyId() const { return rentalCompanyId; }
