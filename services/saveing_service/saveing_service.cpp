#include "../../models/header.h"

void export_to_csv(const vector<Student> &students)
{
    ofstream outFile("students_data.csv");

    if (!outFile)
    {
        cout << "Error opening file for export!" << endl;
        return;
    }

    outFile << "ID,Name,Age,Level" << endl;

    for (const auto &s : students)
    {
        outFile << s.id << ","
                << s.name << ","
                << s.age << ","
                << s.study_level << endl;
    }

    outFile.close();

    cout << "Data exported successfully to students_data.csv!" << endl;
}

void import_from_csv(vector<Student> &students)
{
    ifstream inFile("students_data.csv");

    if (!inFile)
    {
        cout << "No existing data file found. Starting with empty list.\n";
        return;
    }

    string line;
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string temp;
        Student s;

        getline(ss, temp, ',');
        s.id = stoi(temp);

        getline(ss, s.name, ',');

        getline(ss, temp, ',');
        s.age = stoi(temp);

        getline(ss, s.study_level, ',');

        students.push_back(s);
    }

    inFile.close();
    cout << "Data loaded successfully! Total students: " << students.size() << endl;
}