#include "Student.h"
#include <iostream>

Student::Student(int id, std::string name, double marks) {
    this->id = id;
    this->name = name;
    this->marks = marks;
}

void Student::displayDetails() {
    std::cout << "Student ID: " << id << std::endl;
    std::cout << "Student Name: " << name << std::endl;
    std::cout << "Student Marks: " << marks << std::endl;
}

bool Student::hasPassed() {
    return marks >= 40;
}

char Student::calculateGrade() {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 40) return 'D';

    return 'F';
}