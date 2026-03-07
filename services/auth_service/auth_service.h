#ifndef Auth_Service_H
#define Auth_Service_H

#include "../../models/header.h"

string check_login_from_db(string username, string password);
void register_user_db(string username, string password, string role);

#endif