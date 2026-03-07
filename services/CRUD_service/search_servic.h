#ifndef SEARCH_H
#define SEARCH_H

#include "../../models/header.h"

bool Find_id(const vector<Student> &list, int search_id);
void search_by_id(vector<Student> &list);
int find_student_by_id(vector<Student> &list, int search_id);
void search_by_id_from_db();
#endif