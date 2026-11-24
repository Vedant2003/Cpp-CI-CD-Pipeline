
#include <gtest/gtest.h>
#include "../src/Student.h"

namespace {
    constexpr int STUDENT_ID_101 = 101;
    constexpr int STUDENT_ID_102 = 102;
    constexpr int STUDENT_ID_103 = 103;
    constexpr int STUDENT_ID_104 = 104;
    constexpr int STUDENT_ID_105 = 105;

    constexpr double MARKS_85 = 85;
    constexpr double MARKS_30 = 30;
    constexpr double MARKS_40 = 40;
    constexpr double MARKS_95 = 95;
    constexpr double MARKS_80 = 80;
    constexpr double MARKS_65 = 65;
    constexpr double MARKS_50 = 50;
}

TEST(StudentTest, StudentPasses) {
    Student student(STUDENT_ID_101, "Vedant", MARKS_85);
    EXPECT_TRUE(student.hasPassed());
}

TEST(StudentTest, StudentFails) {
    Student student(STUDENT_ID_102, "Rahul", MARKS_30);
    EXPECT_FALSE(student.hasPassed());
}

TEST(StudentTest, StudentPassesAtBoundary) {
    Student student(STUDENT_ID_103, "Aman", MARKS_40);
    EXPECT_TRUE(student.hasPassed());
}

TEST(StudentTest, GradeA) {
    Student student(STUDENT_ID_101, "Vedant", MARKS_95);
    EXPECT_EQ(student.calculateGrade(), 'A');
}

TEST(StudentTest, GradeB) {
    Student student(STUDENT_ID_102, "Rahul", MARKS_80);
    EXPECT_EQ(student.calculateGrade(), 'B');
}

TEST(StudentTest, GradeC) {
    Student student(STUDENT_ID_103, "Aman", MARKS_65);
    EXPECT_EQ(student.calculateGrade(), 'C');
}

TEST(StudentTest, GradeD) {
    Student student(STUDENT_ID_104, "Rohan", MARKS_50);
    EXPECT_EQ(student.calculateGrade(), 'D');
}

TEST(StudentTest, GradeF) {
    Student student(STUDENT_ID_105, "Karan", MARKS_30);
    EXPECT_EQ(student.calculateGrade(), 'F');
}
