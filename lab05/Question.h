#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

#include <string>
#include <vector>
#include "Answer.h"

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;

public:
    Question(string text="") : text(text) {};

    Question();

    const string &getText() const {
        return text;
    };

    const vector<Answer> &getAnswers() const {
        return answers;
    };

    string setText(string text) {
        this->text = text;
        return text;
    };

    vector<Answer> setAnswers(vector<Answer> answers) {
        this->answers = answers;
        return answers;
    };
};

#endif //LAB5_QUESTION_H
