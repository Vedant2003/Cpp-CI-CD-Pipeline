
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {

private:
    int id;
    string name;
    double marks;

public:
    Student(int id, string name, double marks);

    void displayDetails();

    bool hasPassed();

    char calculateGrade();
};

#endif
