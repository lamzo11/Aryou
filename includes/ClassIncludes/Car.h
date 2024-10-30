#ifndef CAR_H
#define CAR_H

class Car {
private:
    int id;
    int cleanlinessLevel;
    int fuelLevel;
    int rentalCompanyId;

public:
    Car(int id, int cleanliness, int fuel, int companyId);
    
    // Getters
    int getId() const;
    int getCleanlinessLevel() const;
    int getFuelLevel() const;
    int getRentalCompanyId() const;
};

#endif
