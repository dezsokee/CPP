#include <fstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file (filename);
    if( !file) {
        cerr <<"Not found"<<endl;
        exit (1);
    }

    int actualID;
    string actualLastName;
    string actualFirstName;

    while (file>>actualID>>actualFirstName>>actualLastName) {
        Student actualStudent(actualID, actualFirstName, actualLastName);
        students.insert({actualID, actualStudent});
    }

    file.close();
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream file;
    file.open(filename);

    if( !file) {
        cerr <<"Not found"<<endl;
        exit (1);
    }

    int studentID;
    double actualMark;

    while (file >> studentID >> actualMark) {
        try {
            students.at(studentID).addGrade(subject,actualMark);
        }
        catch (out_of_range& e) {
            cerr << studentID << " does not exist!" <<endl;
        }
    }

    file.close();
}

void GraduationDao::computeAverage() {
    for(auto &x : students) {
        x.second.computeAverage();
    }
}

int GraduationDao::numPassed() const {
    int sum = 0;

    for(auto x : students) {
        if(x.second.getAverage() != 0) {
            sum++;
        }
    }

    return sum;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double avg = 0;
    int k = 0;

    for ( auto x : students) {
        for (auto y : x.second.getGrades()) {
            if (y.first == subject) {
                avg += y.second;
                k++;
            }
        }
    }

    return avg / k;
}

const map<int, Student> &GraduationDao::getStudents() const {
    return students;
}
