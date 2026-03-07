#include "../../models/header.h"

void save_student_to_db(Student &S)
{
    sqlite3 *DB;
    sqlite3_open("system.db", &DB);
    sqlite3_stmt *stmt;

    string sql = "INSERT INTO Students VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

    sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_int(stmt, 1, S.id);
    sqlite3_bind_text(stmt, 2, S.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, S.age);
    sqlite3_bind_text(stmt, 4, S.study_level.c_str(), -1, SQLITE_STATIC);

    int bind_idx = 5;
    for (int i = 0; i < 5; i++)
    {
        sqlite3_bind_text(stmt, bind_idx++, S.course[i].course_name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, bind_idx++, S.course[i].grade);
    }

    double total = 0;
    for (int i = 0; i < 5; i++)
        total += S.course[i].grade;
    sqlite3_bind_double(stmt, 15, total / 5.0);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}