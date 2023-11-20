#ifndef PARCIALIS_2023_DEZSO_SZABOLCS_COMPANY_H
#define PARCIALIS_2023_DEZSO_SZABOLCS_COMPANY_H

#include <iostream>
#include <string>
#include "Developer.h"
#include "Project.h"

using namespace std;

class Company {
private:
    string name;
    vector<Project> projects;
    vector<Developer> developers;
public:
    Company(const string &name);

    void addProject(const Project &project);

    void addDeveloper(const Developer &developer);

    void printDevelopers() const;

    void printProjects() const;

    void printActiveProjects() const;

    void readProjects(const string &fileName);

    void readDevelopers(const string &fileName);

    void readProjectDevelopers(const string &fileName);

    void printDevelopersOrderedBySalary();

    void printDevelopersOrderedByName();

    void printProjectsOrderedByStartYearAndName();

    Developer *getDeveloperWithMaxProjects() const;
};


#endif //PARCIALIS_2023_DEZSO_SZABOLCS_COMPANY_H
