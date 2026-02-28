#include "../models/header.h"

using namespace std;

void Show_Student_data(vector<Student> students)
{
    cout << "ID     |Name   |Age   |Level\n";
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].id << "|"
             << students[i].name << "|"
             << students[i].age << "|"
             << students[i].study_level << endl;
    }
}
void Show_one_Student_data(Student students)
{
    cout << "ID     |Name   |Age   |Level\n";

    cout << students.id << "|"
         << students.name << "|"
         << students.age << "|"
         << students.study_level << endl;
}
