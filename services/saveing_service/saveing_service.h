#ifndef SAVE_H
#define SAVE_H

#include "../../models/header.h"

void export_to_csv(const vector<Student> &students);
void import_from_csv(vector<Student> &students);
#endif