#include "Project.h"

int Project::counter = 1;

Project::Project(const string &name, const int &startYear, const int &endYear) {
    this->id = counter;
    counter++;
    this->name = name;
    this->startYear = startYear;
    this->endYear = endYear;
}

Project::Project(const string &name, const int &startYear) {
    this->id = counter;
    counter++;
    this->name = name;
    this->startYear = startYear;
    this->endYear = 0;
}

ostream &operator<<(ostream &os, const Project &project) {
    if(project.endYear == 0) {
        os<<project.id<<". project "<<project.name<<" started in "<<project.startYear<<" and the project is still under development"<<endl;
    } else {
        os<<project.id<<". project "<<project.name<<" started in "<<project.startYear<<" and ended in "<<project.endYear<<endl;
    }

    os<<"The developers of the project are:"<<endl;
    for(auto &x : project.developers) {
        os<<*x<<endl;
    }

    return os;
}

void Project::addDeveloper(Developer *developer) {
    developers.push_back(developer);
}

const string &Project::getName() const {
    return name;
}

int Project::getStartYear() const {
    return startYear;
}

int Project::getEndYear() const {
    return endYear;
}

const vector<Developer *> &Project::getDevelopers() const {
    return developers;
}


