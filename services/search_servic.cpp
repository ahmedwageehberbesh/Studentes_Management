#include "../models/header.h"

bool Find_id(const vector<Student> &list, int search_id)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].id == search_id)
        {
            return true;
        }
    }
    return false;
}