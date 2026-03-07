#ifndef Load_Service_H
#define Load_Service_H

#include "../../models/header.h"

void load_students_from_db(vector<Student> &list);
void update_student_db_service(vector<Student> &students);

#endif