#include "../../models/header.h"

void print_header()
{
    cout << string(150, '=') << endl;
    cout << left << setw(10) << "ID"
         << " | " << setw(15) << "Name"
         << " | " << setw(4) << "Age"
         << " | " << setw(6) << "Level"
         << " | " << setw(18) << "Course 1 (G)"
         << " | " << setw(18) << "Course 2 (G)"
         << " | " << setw(18) << "Course 3 (G)"
         << " | " << setw(18) << "Course 4 (G)"
         << " | " << setw(18) << "Course 5 (G)"
         << " | " << setw(6) << "GPA" << endl;
    cout << string(150, '-') << endl;
}

void Show_Student_data(vector<Student> students)
{
    if (students.empty())
    {
        cout << "\n[System] No students found.\n";
        return;
    }

    print_header();
    for (const auto &s : students)
    {
        cout << left << setw(10) << s.id
             << " | " << setw(15) << s.name
             << " | " << setw(4) << s.age
             << " | " << setw(6) << s.study_level;

        for (int i = 0; i < 5; i++)
        {
            string c_info = s.course[i].course_name + " (" + to_string((int)s.course[i].grade) + ")";
            cout << " | " << setw(18) << c_info;
        }

        cout << " | " << setw(6) << fixed << setprecision(2) << s.gpa << endl;
    }
    cout << string(150, '=') << endl;
}
void Show_one_Student_data(Student s)
{
    print_header();

    cout << left << setw(10) << s.id
         << " | " << setw(15) << s.name
         << " | " << setw(4) << s.age
         << " | " << setw(6) << s.study_level;

    for (int i = 0; i < 5; i++)
    {
        string c_info = s.course[i].course_name + " (" + to_string((int)s.course[i].grade) + ")";
        cout << " | " << setw(18) << c_info;
    }

    cout << " | " << setw(6) << fixed << setprecision(2) << s.gpa << endl;
    cout << string(150, '=') << endl;
}