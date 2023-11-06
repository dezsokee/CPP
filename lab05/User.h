#ifndef LAB5_USER_H
#define LAB5_USER_H
#include <iostream>
#include <map>

using namespace std;

class User {
private:
    int id;
    string name;
    map<string, double> scores;
    static int counter;
public:
    User(const string& name);
    int getId() const;
    const string& getName() const;
    void addScore(const string& quizName, double score);
    double getScore(const string& quizName) const;
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif //LAB5_USER_H
