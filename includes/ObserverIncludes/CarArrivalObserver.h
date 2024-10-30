#ifndef CARARRIVALOBSERVER_H
#define CARARRIVALOBSERVER_H

#include "Observer.h"
#include <iostream>

class CarArrivalObserver : public Observer {
public:
    void update() override {
        std::cout << "CarArrivalObserver: A new car has arrived and will be assigned.\n";
        // Additional logic for handling car arrival
    }
};

#endif
