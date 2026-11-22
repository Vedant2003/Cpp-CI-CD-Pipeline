
#include <gtest/gtest.h>
#include "../src/Student.h"

// Test 1: Student passes with marks above 40
TEST(StudentTest, StudentPasses) {
    Student student(101, "Vedant", 85);

    EXPECT_TRUE(student.hasPassed());
}

// Test 2: Student fails with marks below 40
TEST(StudentTest, StudentFails) {
    Student student(102, "Rahul", 30);

    EXPECT_FALSE(student.hasPassed());
}

// Test 3: Student passes with exactly 40 marks
TEST(StudentTest, StudentPassesAtBoundary) {
    Student student(103, "Aman", 40);

    EXPECT_TRUE(student.hasPassed());
}

// Test 4: Grade A
TEST(StudentTest, GradeA) {
    Student student(101, "Vedant", 95);

    EXPECT_EQ(student.calculateGrade(), 'A');
}

// Test 5: Grade B
TEST(StudentTest, GradeB) {
    Student student(102, "Rahul", 80);

    EXPECT_EQ(student.calculateGrade(), 'B');
}

// Test 6: Grade C
TEST(StudentTest, GradeC) {
    Student student(103, "Aman", 65);

    EXPECT_EQ(student.calculateGrade(), 'C');
}

// Test 7: Grade D
TEST(StudentTest, GradeD) {
    Student student(104, "Rohan", 50);

    EXPECT_EQ(student.calculateGrade(), 'D');
}

// Test 8: Grade F
TEST(StudentTest, GradeF) {
    Student student(105, "Karan", 30);

    EXPECT_EQ(student.calculateGrade(), 'F');
}
