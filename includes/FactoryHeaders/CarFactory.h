#ifndef CARFACTORY_H
#define CARFACTORY_H

#include "../ClassIncludes/Car.h"

class CarFactory {
public:
    // Static method to create a Car instance
    static Car createCar(int id, int cleanlinessLevel, int fuelLevel, int rentalCompanyId);
};

#endif
