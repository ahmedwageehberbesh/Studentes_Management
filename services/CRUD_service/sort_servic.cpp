#include "../../models/header.h"
void sort_Students_by_id(vector<Student> &Students)
{
    for (int i = 0; i < Students.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Students[j].id > Students[j + 1].id)
            {
                Student temp = Students[j];
                Students[j] = Students[j + 1];
                Students[j + 1] = temp;
            }
        }
    }
}