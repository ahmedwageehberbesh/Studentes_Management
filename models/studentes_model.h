#ifndef STUDENTS_MODEL_H
#define STUDENTS_MODEL_H
// Ahmed Wageeh Mohamed 20230075
using namespace std;

struct course
{
    string course_name;
    double grade;
    int credits = 3;
};

struct Student
{
    int id;
    string name;
    string study_level;
    int age;
    course course[5];
    double gpa;
};

#endif