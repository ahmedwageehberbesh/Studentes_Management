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
             << students[i].studey_level << endl;
    }
}