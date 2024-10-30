#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int id;
    std::string name;
    bool isPermanent;
    bool isOnBreak;
    int experienceLevel;

public:
    Employee(int id, const std::string& name, bool permanent, int experience);
    
    // Getters
    int getId() const;
    const std::string& getName() const;
    bool getIsPermanent() const;
    bool getIsOnBreak() const;
    int getExperienceLevel() const;

    // Methods to manage break status
    void startBreak();
    void endBreak();
};

#endif
