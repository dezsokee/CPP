#ifndef PARCIALIS_2023_DEZSO_SZABOLCS_DEVELOPER_H
#define PARCIALIS_2023_DEZSO_SZABOLCS_DEVELOPER_H

#include <iostream>
#include <string>

using namespace std;

enum Level {
    JUNIOR, MID, SENIOR
};

class Developer {
private:
    static int counter;
    int id;
    string name;
    double salary;
    enum Level level;
public:
    Developer(const string &name, const double &salary, enum Level level);

    friend ostream &operator<<(ostream &os, const Developer &developer);

    const string &getName() const;

    double getSalary() const;

    Level getLevel() const;

    int getId() const;
};


#endif //PARCIALIS_2023_DEZSO_SZABOLCS_DEVELOPER_H
