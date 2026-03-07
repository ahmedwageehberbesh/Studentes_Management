#include "../../models/header.h"

bool Find_id(const vector<Student> &list, int search_id)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].id == search_id)
            return true;
    }
    return false;
}

void search_by_id(vector<Student> &list)
{
    int search_id;
    cout << "Enter ID : ";
    cin >> search_id;

    int low = 0, high = list.size() - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (list[mid].id == search_id)
        {
            Show_one_Student_data(list[mid]);
            found = true;
            break;
        }
        else if (list[mid].id < search_id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (!found)
        cout << "Student with ID " << search_id << " not found." << endl;
}

int find_student_by_id(vector<Student> &list, int search_id)
{
    int low = 0, high = list.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (list[mid].id == search_id)
        {
            return mid;
        }
        else if (list[mid].id < search_id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
#include "../../models/header.h"

void search_by_id_from_db()
{
    int search_id;
    cout << "Enter Student ID to search in Database: ";
    cin >> search_id;

    sqlite3 *DB;
    sqlite3_open("system_data.db", &DB);
    sqlite3_stmt *stmt;

    string sql = "SELECT * FROM Students WHERE ID = ?;";

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, search_id);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            Student S;
            S.id = sqlite3_column_int(stmt, 0);
            S.name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            S.age = sqlite3_column_int(stmt, 2);
            S.study_level = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

            int col = 4;
            for (int i = 0; i < 5; i++)
            {
                S.course[i].course_name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, col++));
                S.course[i].grade = sqlite3_column_double(stmt, col++);
            }
            S.gpa = sqlite3_column_double(stmt, 14);

            Show_one_Student_data(S);
        }
        else
        {
            cout << "\n[System] Student with ID " << search_id << " not found in Database.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}