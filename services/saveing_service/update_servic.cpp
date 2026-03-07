#include "../../models/header.h"

void update_student_db_service(vector<Student> &students)
{
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    int index = find_student_by_id(students, id);
    if (index == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    string new_name;
    int new_age;
    cout << "Enter New Name: ";
    cin.ignore();
    getline(cin, new_name);
    cout << "Enter New Age: ";
    cin >> new_age;

    sqlite3 *DB;
    sqlite3_open("system_data.db", &DB);
    sqlite3_stmt *stmt;

    string sql = "UPDATE Students SET Name = ?, Age = ? WHERE StudentID = ?;";

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, new_name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, new_age);
        sqlite3_bind_int(stmt, 3, id);

        if (sqlite3_step(stmt) == SQLITE_DONE)
        {
            students[index].name = new_name;
            students[index].age = new_age;
            cout << "[Success] Data updated in Database and Memory." << endl;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}