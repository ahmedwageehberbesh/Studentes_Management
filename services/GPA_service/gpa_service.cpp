#include "../../models/header.h"

double get_grade_points(double grade)
{
    if (grade >= 90)
        return 4.0;
    if (grade >= 85)
        return 3.7;
    if (grade >= 80)
        return 3.3;
    if (grade >= 75)
        return 3.0;
    if (grade >= 70)
        return 2.7;
    if (grade >= 65)
        return 2.4;
    if (grade >= 60)
        return 2.0;
    if (grade >= 50)
        return 1.0;
    return 0.0;
}

string get_rating(double gpa)
{
    if (gpa >= 3.7)
        return "Excellent (A)";
    if (gpa >= 3.0)
        return "Very Good (B)";
    if (gpa >= 2.0)
        return "Good (C)";
    if (gpa >= 1.0)
        return "Pass (D)";
    return "Fail (F)";
}

void calculate_and_assign_gpa(Student &S)
{
    double total_points = 0.0;
    int total_hours = 0;

    for (int i = 0; i < 5; i++)
    {
        double points = get_grade_points(S.course[i].grade);
        total_points += (points * S.course[i].credits);
        total_hours += S.course[i].credits;
    }

    if (total_hours > 0)
    {
        S.gpa = total_points / total_hours;
        string rating = get_rating(S.gpa);

        cout << "\n[Success] Calculated GPA for " << S.name << " is: "
             << fixed << setprecision(2) << S.gpa << " / 4.00"
             << " | Rating: " << rating << endl;
    }
}