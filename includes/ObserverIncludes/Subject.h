#ifndef SUBJECT_H
#define SUBJECT_H
#include<algorithm>
#include <vector>
#include "Observer.h"

class Subject {
protected:
    std::vector<Observer*> observers;  // List of observers

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();  // Call the update method on each observer
        }
    }
};

#endif
