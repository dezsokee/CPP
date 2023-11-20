#include "Developer.h"

int Developer::counter = 1;

Developer::Developer(const string &name, const double &salary, enum Level level) {
    this->id = counter;
    counter++;
    this->name = name;
    this->salary = salary;
    this->level = level;
}

ostream &operator<<(ostream &os, const Developer &developer) {
    string developerLevel;

    switch (developer.level) {
        case 0:
            developerLevel = "junior";
            break;
        case 1:
            developerLevel = "mid";
            break;
        case 2:
            developerLevel = "senior";
            break;
    }

    os<<developer.id<<".th developer: "<<developer.name<<" has "<<developer.salary<<" salary with "<<developerLevel<<" level"<<endl;
    return os;
}

const string &Developer::getName() const {
    return name;
}

double Developer::getSalary() const {
    return salary;
}

Level Developer::getLevel() const {
    return level;
}

int Developer::getId() const {
    return id;
}
