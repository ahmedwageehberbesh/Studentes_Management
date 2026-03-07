#include "../../models/header.h"

void add_Student(Student &S, vector<Student> &students)
{
    cout << "Enter ID: ";
    cin >> S.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, S.name);
    cout << "Enter Age: ";
    cin >> S.age;
    cout << "Enter Level: ";
    cin.ignore();
    getline(cin, S.study_level);

    sqlite3 *DB;
    sqlite3_open("system_data.db", &DB);

    string sqlS = "INSERT INTO Students (StudentID, Name, Age, Level) VALUES (?, ?, ?, ?);";
    sqlite3_stmt *stmtS;
    sqlite3_prepare_v2(DB, sqlS.c_str(), -1, &stmtS, NULL);
    sqlite3_bind_int(stmtS, 1, S.id);
    sqlite3_bind_text(stmtS, 2, S.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmtS, 3, S.age);
    sqlite3_bind_text(stmtS, 4, S.study_level.c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmtS);
    sqlite3_finalize(stmtS);

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Course Name " << i + 1 << ": ";
        cin.ignore();
        getline(cin, S.course[i].course_name);

        do
        {
            cout << "Enter Course grade " << i + 1 << " (0-100): ";
            cin >> S.course[i].grade;

            if (S.course[i].grade < 0 || S.course[i].grade > 100)
            {
                cout << "[Error] Invalid grade! Please enter a value between 0 and 100.\n";
            }
        } while (S.course[i].grade < 0 || S.course[i].grade > 100);

        string sqlC = "INSERT OR IGNORE INTO Courses (CourseName) VALUES (?);";
        sqlite3_stmt *stmtC;
        sqlite3_prepare_v2(DB, sqlC.c_str(), -1, &stmtC, NULL);
        sqlite3_bind_text(stmtC, 1, S.course[i].course_name.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmtC);
        sqlite3_finalize(stmtC);

        int courseID = (int)sqlite3_last_insert_rowid(DB);

        string sqlR = "INSERT INTO StudentCourses (StudentID, CourseID, Grade) VALUES (?, ?, ?);";
        sqlite3_stmt *stmtR;
        sqlite3_prepare_v2(DB, sqlR.c_str(), -1, &stmtR, NULL);
        sqlite3_bind_int(stmtR, 1, S.id);
        sqlite3_bind_int(stmtR, 2, courseID);
        sqlite3_bind_double(stmtR, 3, S.course[i].grade);
        sqlite3_step(stmtR);
        sqlite3_finalize(stmtR);
    }
    sqlite3_close(DB);
}