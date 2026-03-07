#include "models/header.h"

void run()
{
    initialize_db();

    string username, password, userRole = "Invalid";
    int initialChoice;

    cout << "--- Welcome to Student System ---\n";
    cout << "1. Login\n";
    cout << "2. Create New Account\n";
    cout << "Choice: ";
    cin >> initialChoice;

    if (initialChoice == 2)
    {
        string newUsername, newPassword, role;
        cout << "\n--- Create Account ---\n";
        cout << "Enter Username: ";
        cin >> newUsername;
        cout << "Enter Password: ";
        cin >> newPassword;
        cout << "Enter Role (Admin/Staff): ";
        cin >> role;

        register_user_db(newUsername, newPassword, role);
        cout << "Account created successfully! Please login.\n";
    }

    cout << "\n--- Login System ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    userRole = check_login_from_db(username, password);

    if (userRole == "Invalid")
    {
        cout << "Access Denied! Incorrect username or password.\n";
        return;
    }

    vector<Student> students;
    load_students_from_db(students);

    int choice;
    do
    {
        cout << "\nWelcome " << username << " (" << userRole << ")";
        cout << "\n1. Add Student & Courses";
        cout << "\n2. Show All Students";
        cout << "\n3. Search Student (DB)";
        cout << "\n4. Delete Student";
        cout << "\n5. Update Student Data";
        cout << "\n0. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student s;
            add_Student(s, students);
            load_students_from_db(students);
            break;
        }
        case 2:
            Show_Student_data(students);
            break;
        case 3:
            search_by_id_from_db();
            break;
        case 4:
            if (userRole == "Admin")
            {
                delete_service(students);
            }
            else
            {
                cout << "Error: Only Admins can delete records!\n";
            }
            break;
        case 5:
            update_student_db_service(students);
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
}