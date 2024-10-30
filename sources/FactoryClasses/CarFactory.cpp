#include "../../includes/FactoryHeaders/CarFactory.h"

// Implementation of the createCar method
Car CarFactory::createCar(int id, int cleanlinessLevel, int fuelLevel, int rentalCompanyId) {
    return Car(id, cleanlinessLevel, fuelLevel, rentalCompanyId);
}
