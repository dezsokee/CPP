#include <fstream>
#include <algorithm>
#include "Company.h"

Company::Company(const string &name) {
    this->name = name;
}

void Company::addProject(const Project &project) {
    projects.push_back(project);
}

void Company::addDeveloper(const Developer &developer) {
    developers.push_back(developer);
}

void Company::printDevelopers() const {
    cout<<"The developers of the company are:"<<endl;
    for(auto &x : developers)
        cout<< x <<endl;
}

void Company::printProjects() const {
    cout<<"The projects of the company are:"<<endl;
    for(auto &x : projects)
        cout<< x <<endl;
}

void Company::printActiveProjects() const {
    for(auto &x : projects) {
        if(x.getEndYear() == 0) {
            cout<<x<<endl;
        }
    }
}

void Company::readProjects(const string &fileName) {
    ifstream file;
    file.open(fileName);

    string actualName;
    int actualStartYear;
    int actualEndDate;

    while(file>>actualName>>actualStartYear>>actualEndDate){
        Project actualProject(actualName, actualStartYear, actualEndDate);
        projects.push_back(actualProject);
    }

    file.close();
}

void Company::readDevelopers(const string &fileName) {
    ifstream file;
    file.open(fileName);

    string actualName;
    double actualSalary;
    int actualLevel;
    enum Level actualEnumLevel;

    while(file>>actualName>>actualSalary>>actualLevel){

        switch (actualLevel) {
            case 1:
                actualEnumLevel = JUNIOR;
                break;
            case 2:
                actualEnumLevel = MID;
                break;
            case 3:
                actualEnumLevel = SENIOR;
                break;
        }
        
        Developer actualDeveloper(actualName, actualSalary, actualEnumLevel);
        developers.push_back(actualDeveloper);
    }

    file.close();
}

void Company::readProjectDevelopers(const string &fileName) {
    ifstream file;
    file.open(fileName);

    int actualDeveloper;
    int actualProject;

    while(file>>actualProject>>actualDeveloper){
        projects[actualProject-1].addDeveloper(&developers[actualDeveloper-1]);
    }

    file.close();
}

bool cmp(const Developer &a, const Developer &b) {
    return a.getSalary() < b.getSalary();
}

void Company::printDevelopersOrderedBySalary() {
    sort(developers.begin(),developers.end(), cmp);
    cout<<"After sorting the developers by their salaries:"<<endl;
    printDevelopers();
}

bool cmp2(const Developer &a, const Developer &b) {
    return a.getName() < b.getName();
}

void Company::printDevelopersOrderedByName() {
    sort(developers.begin(),developers.end(), cmp2);
    cout<<"After sorting the developers by their names:"<<endl;
    printDevelopers();
}

bool cmp3(const Project &a, const Project &b) {
    if(a.getStartYear() < b.getStartYear()) {
        return true;
    } else if (a.getStartYear() > b.getStartYear()) {
        return false;
    } else if (a.getStartYear() == b.getStartYear()) {
        return a.getName() < b.getName();
    }
}

void Company::printProjectsOrderedByStartYearAndName() {
    sort(projects.begin(),projects.end(), cmp3);
    cout<<"After sorting the project by their start years and then their names:"<<endl;
    printProjects();
}

Developer *Company::getDeveloperWithMaxProjects() const {
    int *counter[developers.size()];

    for (int i = 0; i < developers.size(); ++i) {
        counter[i] = 0;
    }

    for (int i = 0; i < developers.size(); ++i) {
        cout<<counter[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < projects.size(); ++i) {
        for (int j = 0; j < projects[i].getDevelopers().size(); ++j) {
            vector<Developer *> workingDevelopers = projects[i].getDevelopers();
            /*for (int k = 0; k < workingDevelopers.size(); ++k) {
                cout<<*workingDevelopers[k]<<endl;
            }*/
            int actualID = workingDevelopers[j]->getId();
            counter[actualID]++;
        }
    }

    /*for (int i = 0; i < developers.size(); ++i) {
        cout<<counter[i]<<" ";
    }*/

    /*int maxi = -1;

    for (int i = 0; i < developers.size(); ++i) {
        if(*counter[i] > maxi) {
            maxi = *counter[i];
        }
    }*/

    return 0;
}


