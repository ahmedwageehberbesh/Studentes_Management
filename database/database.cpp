#include "../models/header.h"

void initialize_db()
{
    sqlite3 *DB;
    char *zErrMsg = 0;
    int rc = sqlite3_open("system_data.db", &DB);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(DB) << endl;
        return;
    }

    string sql =
        "CREATE TABLE IF NOT EXISTS Users ("
        "UserID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "Username TEXT NOT NULL UNIQUE, "
        "Password TEXT NOT NULL, "
        "Role TEXT NOT NULL);"

        "CREATE TABLE IF NOT EXISTS Students ("
        "StudentID INTEGER PRIMARY KEY, "
        "Name TEXT NOT NULL, "
        "Age INTEGER, "
        "Level TEXT);"

        "CREATE TABLE IF NOT EXISTS Courses ("
        "CourseID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "CourseName TEXT NOT NULL, "
        "Credits INTEGER DEFAULT 3);"

        "CREATE TABLE IF NOT EXISTS StudentCourses ("
        "StudentID INTEGER, "
        "CourseID INTEGER, "
        "Grade REAL, "
        "FOREIGN KEY(StudentID) REFERENCES Students(StudentID), "
        "FOREIGN KEY(CourseID) REFERENCES Courses(CourseID));";

    rc = sqlite3_exec(DB, sql.c_str(), NULL, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error during initialization: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "[Database] All relational tables are ready!" << endl;
    }
    sqlite3_close(DB);
}