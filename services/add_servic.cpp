#include "../models/header.h"

using namespace std;

void add_Student(Student &S, vector<Student> Student)
{
    do
    {
        cout << "\nEnter ID : ";
        cin >> S.id;
    } while (search_id(Student));
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, S.name);
    cout << "Enter Age :";
    cin >> S.age;
    cout << "Enter Level: ";
    cin.ignore();
    getline(cin, S.studey_level);
}