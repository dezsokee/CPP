#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>
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

    vector<Answer> getAnswers() {
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

    void randomizeAnswers() {
        srand(time(NULL));
        unsigned seed = rand();
        shuffle(this->answers.begin(), this->answers.end(), default_random_engine(seed));
    };
};

#endif //LAB5_QUESTION_H
