#include "Student.h"
#include <iostream>

int main() {
    constexpr int STUDENT_ID = 101;
    constexpr double STUDENT_MARKS = 85;

    Student s1(STUDENT_ID, "Vedant", STUDENT_MARKS);

    std::cout << "----- Student Management System -----\n";

    s1.displayDetails();

    std::cout << "Passed: "
              << (s1.hasPassed() ? "Yes" : "No") << '\n';

    std::cout << "Grade: "
              << s1.calculateGrade() << '\n';

    return 0;
}
