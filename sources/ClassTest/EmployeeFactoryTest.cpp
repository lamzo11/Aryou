#include <iostream>
#include "../../includes/FactoryHeaders/EmployeeFactory.h"

void testEmployeeFactory() {
    std::cout << "Testing EmployeeFactory...\n";

    // Test Case 1: Create a permanent employee with high experience
    Employee employee1 = EmployeeFactory::createEmployee(1, "Alice Johnson", true, 5);
    std::cout << "Employee ID: " << employee1.getId() << " | Name: " << employee1.getName() 
              << " | Permanent: " << (employee1.getIsPermanent() ? "Yes" : "No")
              << " | Experience Level: " << employee1.getExperienceLevel() << "\n";

    // Expected Output: ID = 1, Name = Alice Johnson, Permanent = Yes, Experience = 5

    // Test Case 2: Create a temporary employee with lower experience
    Employee employee2 = EmployeeFactory::createEmployee(2, "Bob Smith", false, 2);
    std::cout << "Employee ID: " << employee2.getId() << " | Name: " << employee2.getName() 
              << " | Permanent: " << (employee2.getIsPermanent() ? "Yes" : "No")
              << " | Experience Level: " << employee2.getExperienceLevel() << "\n";

    // Expected Output: ID = 2, Name = Bob Smith, Permanent = No, Experience = 2

    // Additional assertions (optional): You may add assertions or conditionals to check
    // if the values match expectations for automated testing.
}

int main() {
    testEmployeeFactory();
    return 0;
}
