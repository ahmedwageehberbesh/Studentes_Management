#ifndef HEADER_H
#define HEADER_H
// Ahmed Wageeh Mohamed 20230075
//  1.   (Standard Libraries)
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// 2.  (Models)
#include "../models/studentes_model.h"

// 3. lib
#include "../sqlite3/sqlite3.h"

// 4.  (Services)
#include "../services/CRUD_service/add_servic.h"
#include "../services/CRUD_service/show_servic.h"
#include "../services/CRUD_service/search_servic.h"
#include "../services/CRUD_service/srot_servic.h"
#include "../services/CRUD_service/delete_servic.h"
#include "../services/CRUD_service/update_servic.h"
#include "../services/saveing_service/saveing_service.h"
#include "../services/saveing_service/saving_in_database.h"
#include "../services/saveing_service/database_service.h"
#include "../services/auth_service/auth_service.h"
#include "../services/GPA_service/gpa_service.h"
// 5.    (DataBase)
#include "../database/database.h"

#endif