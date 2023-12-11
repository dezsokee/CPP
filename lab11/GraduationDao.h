#ifndef LAB11_GRADUATIONDAO_H
#define LAB11_GRADUATIONDAO_H

#include "Student.h"

class GraduationDao {
    int year{2023};

    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}

    void enrollStudents(const string &filename);

    void saveGradesForSubject(const string &subject, const string &filename);

    void computeAverage();

    int numEnrolled() const;

    int numPassed() const;

    Student findById(int id) const;

    double getAverageBySubject(const string &subject) const;

    const map<int, Student> &getStudents() const;
};


#endif //LAB11_GRADUATIONDAO_H
