#include "../models/header.h"

bool search_id(vector<Student> s)
{
    vector<int> ids;
    for (int i = 0; i < s.size(); i++)
    {

        for (int j = 0; j < ids.size(); j++)
        {
            if (s[i].id == ids[j])
            {
                return true;
            }
        }

        ids.push_back(s[i].id);
    }
    return false;
}