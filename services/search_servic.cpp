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
void search_by_id(vector<Student> &list)
{
    int search_id, find_id, mid, high = list.size(), low = 0;

    cout << "Enter ID :";
    cin >> search_id;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (list[mid].id > search_id)
        {
            low = mid + 1;
        }
        else if (list[mid].id < search_id)
        {
            low = mid - 1;
        }
        else if (list[mid].id == search_id)
        {
            Show_one_Student_data(list[mid]);
            break;
        }
        else
        {
            cout << "Student with ID " << search_id << " not found ,Enter an other ID : ";
            cin >> search_id;
        }
    }
}
int find_student_by_id(vector<Student> &list, int search_id)
{
    int find_id, mid, high = list.size(), low = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (list[mid].id > search_id)
        {
            low = mid + 1;
        }
        else if (list[mid].id < search_id)
        {
            low = mid - 1;
        }
        else if (list[mid].id == search_id)
        {
            return mid;
        }
        else
        {
            cout << "Student with ID " << search_id << " not found ,Enter an other ID : ";
            cin >> search_id;
        }
    }
}