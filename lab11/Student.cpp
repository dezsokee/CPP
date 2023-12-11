#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName), lastName(lastName) {}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades.insert({subject, grade});
}

double Student::getGrade(const string &subject) {
    if (grades.find(subject) == grades.end()) {
        throw out_of_range("Can't find the specific subject!");
    } else {
        return grades.at(subject);
    }
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double avg = 0;

    for (const auto &x: grades) {
        if (x.second < 5) {
            return;
        }
        avg += x.second;
    }

    avg /= grades.size();

    if ( avg >= 6) {
        average = avg;
    }
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.id << ": " << student.firstName << " " << student.lastName << " with avg " << student.average << endl;
    os << "Grades: " << endl;
    for (auto x: student.grades) {
        cout << x.first << " - " << x.second << endl;
    }

    return os;
};
