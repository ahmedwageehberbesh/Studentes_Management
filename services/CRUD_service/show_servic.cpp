#include "../../models/header.h"

using namespace std;

void print_header()
{
    cout << string(50, '-') << endl;
    cout << left << setw(10) << "ID"
         << " | " << setw(15) << "Name"
         << " | " << setw(8) << "Age"
         << " | " << setw(10) << "Level" << endl;
    cout << string(50, '-') << endl;
}

void Show_Student_data(vector<Student> students)
{
    print_header();
    for (int i = 0; i < students.size(); i++)
    {
        cout << left << setw(10) << students[i].id
             << " | " << setw(15) << students[i].name
             << " | " << setw(8) << students[i].age
             << " | " << setw(10) << students[i].study_level << endl;
    }
}
void Show_one_Student_data(Student student)
{
    print_header();
    cout << left << setw(10) << student.id
         << " | " << setw(15) << student.name
         << " | " << setw(8) << student.age
         << " | " << setw(10) << student.study_level << endl;
}
