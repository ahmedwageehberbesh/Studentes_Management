#include "../../models/header.h"

void delete_service(vector<Student> &Students)
{
    int delete_id;
    cout << "Enter ID :";
    cin >> delete_id;

    int index = find_student_by_id(Students, delete_id);

    if (index != -1)
    {
        sqlite3 *DB;
        sqlite3_open("system.db", &DB);

        string sql = "DELETE FROM Students WHERE ID = " + to_string(delete_id) + ";";

        char *errMsg;
        sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
        sqlite3_close(DB);

        Students.erase(Students.begin() + index);
        cout << "\n[System] Student deleted successfully from Database and Memory.\n";
    }
    else
    {
        cout << "\n[Error] Student ID not found!\n";
    }

    Show_Student_data(Students);
}