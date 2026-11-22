#include <iostream>
#include "Student.h"

int main() {
    Student s1(101, "Vedant", 85);

    std::cout << "----- Student Management System -----" << std::endl;

    s1.displayDetails();

    std::cout << "Passed: "
              << (s1.hasPassed() ? "Yes" : "No") << std::endl;

    std::cout << "Grade: "
              << s1.calculateGrade() << std::endl;

    return 0;
}