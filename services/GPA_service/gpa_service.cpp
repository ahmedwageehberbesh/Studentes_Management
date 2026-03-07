#include "../../models/header.h"

void calculate_and_assign_gpa(Student &S)
{
    double total_points = 0.0;
    int total_hours = 0;

    for (int i = 0; i < 5; i++)
    {
        total_points += (S.course[i].grade * S.course[i].credits);
        total_hours += S.course[i].credits;
    }

    if (total_hours > 0)
    {
        double final_gpa = total_points / total_hours;

        cout << "\n[Success] Calculated GPA for " << S.name << " is: " << fixed << setprecision(2) << final_gpa << endl;
    }
}