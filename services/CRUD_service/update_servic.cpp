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

        sqlite3 *DB;
        sqlite3_open("system_data.db", &DB);
        string sql;
        sqlite3_stmt *stmt;

        switch (choice)
        {
        case 1:
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, students[index].name);
            sql = "UPDATE Students SET Name = ? WHERE StudentID = ?;";
            sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
            sqlite3_bind_text(stmt, 1, students[index].name.c_str(), -1, SQLITE_STATIC);
            break;
        case 2:
            cout << "Enter New Age: ";
            cin >> students[index].age;
            sql = "UPDATE Students SET Age = ? WHERE StudentID = ?;";
            sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
            sqlite3_bind_int(stmt, 1, students[index].age);
            break;
        case 3:
            cout << "Enter New Level: ";
            cin.ignore();
            getline(cin, students[index].study_level);
            sql = "UPDATE Students SET Level = ? WHERE StudentID = ?;";
            sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
            sqlite3_bind_text(stmt, 1, students[index].study_level.c_str(), -1, SQLITE_STATIC);
            break;
        default:
            cout << "Update cancelled.\n";
            sqlite3_close(DB);
            return;
        }

        sqlite3_bind_int(stmt, 2, update_id);

        if (sqlite3_step(stmt) == SQLITE_DONE)
        {
            cout << "Student updated successfully in Memory and Database!\n";
        }
        else
        {
            cout << "Error updating Database.\n";
        }

        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        Show_one_Student_data(students[index]);
    }
    else
    {
        cout << "Student not found!\n";
    }
}