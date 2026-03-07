#ifndef GPA_H
#define GPA_H

#include "../../models/header.h"
double get_grade_points(double grade);
string get_rating(double gpa);
void calculate_and_assign_gpa(Student &S);

#endif