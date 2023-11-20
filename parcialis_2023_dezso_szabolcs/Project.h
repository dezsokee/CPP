#ifndef PARCIALIS_2023_DEZSO_SZABOLCS_PROJECT_H
#define PARCIALIS_2023_DEZSO_SZABOLCS_PROJECT_H

#include <iostream>
#include <string>
#include <vector>
#include "Developer.h"

using namespace std;

class Project {
private:
    static int counter;
    int id;
    string name;
    int startYear;
    int endYear;
    vector<Developer *> developers;
public:
    Project(const string &name, const int &startYear, const int &endYear);

    Project(const string &name, const int &startYear);

    void addDeveloper(Developer *developer);

    friend ostream &operator<<(ostream &os, const Project &project);

    const string &getName() const;

    int getStartYear() const;

    int getEndYear() const;

    const vector<Developer *> &getDevelopers() const;
};


#endif //PARCIALIS_2023_DEZSO_SZABOLCS_PROJECT_H
