#include "../models/header.h"

using namespace std;

void add_Student(Student &S, vector<Student> &Student)
{
    int temp_id;
    while (true)
    {
        cout << "\nEnter ID : ";
        cin >> temp_id;
        if (!Find_id(Student, temp_id))
        {
            S.id = temp_id;
            break;
        }
    }
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, S.name);
    cout << "Enter Age :";
    cin >> S.age;
    cout << "Enter Level: ";
    cin.ignore();
    getline(cin, S.study_level);
}