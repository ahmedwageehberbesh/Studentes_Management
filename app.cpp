#include "models/header.h"

void run()
{

    vector<Student> students;
    Student s;
    int choice;

    do
    {

        cout << "\n1. Add Student";
        cout << "\n2. Show Student";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n0. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 4:
            delete_service(students);
            break;
        case 3:
            search_by_id(students);
            break;
        case 2:
            Show_Student_data(students);
            break;
        case 1:
            add_Student(s, students);
            students.push_back(s);
            sort_Students_by_id(students);
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
}