#include "../../models/header.h"

void update_service(vector<Student> &students)
{
    int update_id;
    cout << "Enter ID :";
    cin >> update_id;
    int index = find_student_by_id(students, update_id);
    if (index != -1)
    {
        Show_one_Student_data(students[index]);

        cout << "\n--- Update Menu ---\n";
        cout << "1. Update Name\n";
        cout << "2. Update Age\n";
        cout << "3. Update Level\n";
        cout << "0. Cancel\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, students[index].name);
            break;
        case 2:
            cout << "Enter New Age: ";
            cin >> students[index].age;
            break;
        case 3:
            cout << "Enter New Level: ";
            cin.ignore();
            getline(cin, students[index].study_level);
            break;
        default:
            cout << "Update cancelled.\n";
            return;
        }
        cout << "Student updated successfully!\n";
        Show_one_Student_data(students[index]);
    }
    else
    {
        cout << "Student not found!\n";
    }
}
