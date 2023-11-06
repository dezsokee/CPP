#include "User.h"

int User::counter = 0;

User::User(const string &name) {
    counter++;
    this->id=counter;
    this->name = name;
}

int User::getId() const {
    return this->id;
}

const string &User::getName() const {
    return this->name;
}

void User::addScore(const string &quizName, double score) {
    scores.insert({quizName, score});
}

double User::getScore(const string &quizName) const {
    return scores.at(quizName);
}

ostream &operator<<(ostream &os, const User &user) {
    os<<user.id<<".th user"<<endl;
    os<<user.name<<endl;

    os<<"The scores of the user:"<<endl;

    for(auto const& element : user.scores) {
        os<<element.first<<" <-> "<<element.second<<endl;
    }

    return os;
}
