#include "../../models/header.h"

void load_students_from_db(vector<Student> &list)
{
    list.clear();
    sqlite3 *DB;
    sqlite3_stmt *stmt;

    if (sqlite3_open("system_data.db", &DB) != SQLITE_OK)
        return;

    string sql_students = "SELECT * FROM Students ORDER BY StudentID ASC;";

    if (sqlite3_prepare_v2(DB, sql_students.c_str(), -1, &stmt, NULL) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            Student s;
            s.id = sqlite3_column_int(stmt, 0);
            s.name = (const char *)sqlite3_column_text(stmt, 1);
            s.age = sqlite3_column_int(stmt, 2);
            s.study_level = (const char *)sqlite3_column_text(stmt, 3);

            sqlite3_stmt *course_stmt;
            string sql_courses = "SELECT C.CourseName, SC.Grade, C.Credits "
                                 "FROM StudentCourses SC "
                                 "JOIN Courses C ON SC.CourseID = C.CourseID "
                                 "WHERE SC.StudentID = ?;";

            if (sqlite3_prepare_v2(DB, sql_courses.c_str(), -1, &course_stmt, NULL) == SQLITE_OK)
            {
                sqlite3_bind_int(course_stmt, 1, s.id);

                int i = 0;
                double total_points = 0;
                int total_credits = 0;

                while (sqlite3_step(course_stmt) == SQLITE_ROW && i < 5)
                {
                    s.course[i].course_name = (const char *)sqlite3_column_text(course_stmt, 0);
                    s.course[i].grade = sqlite3_column_double(course_stmt, 1);
                    s.course[i].credits = sqlite3_column_int(course_stmt, 2);

                    total_points += (s.course[i].grade * s.course[i].credits);
                    total_credits += s.course[i].credits;
                    i++;
                }

                s.gpa = (total_credits > 0) ? (total_points / total_credits) : 0.0;
                sqlite3_finalize(course_stmt);
            }
            list.push_back(s);
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}