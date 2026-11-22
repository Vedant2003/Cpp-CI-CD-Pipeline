
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

private:
    int id;
    std::string name;
    double marks;

public:
    Student(int id, std::string name, double marks);

    void displayDetails() const;

    bool hasPassed() const;

    char calculateGrade() const;
};

#endif
