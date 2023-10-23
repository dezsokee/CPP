#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include <string>
#include <stdexcept>
#include "Question.h"

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;
public:
    Quiz(const string &name, const string &fileName);

    const Question &getQuestions(int index) const {
        if (index < 0 || index >= questions.size())
            throw out_of_range("Index out of range");
        return questions[index];
    };

    int getNumQuestion() const {
        return questions.size();
    };

    const string &getName() const {
        return name;
    };

    const vector<Question> &getQuestions() const {
        return questions;
    };

    string setName(string name) {
        this->name = name;
        return name;
    };

    void printQuestions();
};


#endif //LAB5_QUIZ_H
