#include "../../models/header.h"

void delete_service(vector<Student> &Students)
{
    int delete_id;
    cout << "Enter ID :";
    cin >> delete_id;
    int index = find_student_by_id(Students, delete_id);
    Students.erase(Students.begin() + index);
    Show_Student_data(Students);
}