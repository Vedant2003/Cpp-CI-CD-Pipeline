
#include "Student.h"
#include <iostream>
#include <utility>

namespace {
    constexpr double PASS_MARKS = 40;
    constexpr double GRADE_A_MARKS = 90;
    constexpr double GRADE_B_MARKS = 75;
    constexpr double GRADE_C_MARKS = 60;
}

Student::Student(int id, std::string name, double marks)
    : id(id), name(std::move(name)), marks(marks) {
}

void Student::displayDetails() const {
    int unusedVariable = 100; // INTENTIONAL WARNING FOR CI TESTING

    std::cout << "Student ID: " << id << '\n';
    std::cout << "Student Name: " << name << '\n';
    std::cout << "Student Marks: " << marks << '\n';
}

bool Student::hasPassed() const {
    return marks >= PASS_MARKS;
}

char Student::calculateGrade() const {
    if (marks >= GRADE_A_MARKS) {
        return 'A';
    }

    if (marks >= GRADE_B_MARKS) {
        return 'B';
    }

    if (marks >= GRADE_C_MARKS) {
        return 'C';
    }

    if (marks >= PASS_MARKS) {
        return 'D';
    }

    return 'F';
}
