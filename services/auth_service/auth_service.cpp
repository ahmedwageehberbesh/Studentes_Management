#include "../../models/header.h"

string check_login_from_db(string username, string password)
{
    sqlite3 *DB;
    sqlite3_open("system_data.db", &DB);
    sqlite3_stmt *stmt;
    string role = "Invalid";

    string sql = "SELECT ROLE FROM Users WHERE USERNAME = ? AND PASSWORD = ?;";

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            role = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return role;
}

void register_user_db(string username, string password, string role)
{
    sqlite3 *DB;
    sqlite3_open("system_data.db", &DB);
    sqlite3_stmt *stmt;

    string sql = "INSERT INTO Users (USERNAME, PASSWORD, ROLE) VALUES (?, ?, ?);";

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, role.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}