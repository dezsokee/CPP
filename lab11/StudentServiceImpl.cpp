#include "StudentServiceImpl.h"

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> actualSubjects;
    try {
        Student actualStudent = dao->findById(id);
        for(const auto &x : actualStudent.getGrades()) {
            actualSubjects.push_back(x.first);
        }
        return actualSubjects;
    } catch (out_of_range &e) {
        e.what();
        return actualSubjects;
    }
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    try {
        Student actualStudent = dao->findById(id);
        return actualStudent.getGrades().at(subject);
    } catch (out_of_range &e) {
        e.what();
        return -1;
    }
}

bool StudentServiceImpl::isEnrolled(int id) const {
    try{
        dao->findById(id);
        return true;
    }
    catch(out_of_range &e){
        return false;
    }
}

double StudentServiceImpl::getAverage(int id) const {
    try {
        return dao->findById(id).getAverage();
    } catch (out_of_range &e) {
        e.what();
        return false;
    }
}

bool StudentServiceImpl::isPassed(int id) const {
    return dao->findById(id).getAverage();
}
