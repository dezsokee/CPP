#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>
#include "Quiz.h"
#include "Question.h"

using namespace std;

Quiz::Quiz(const string &name, const string &fileName) {
    ifstream file(fileName);
    this->name = name;

    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }

    string line;
    Question question("");
    vector<Answer> answers;

    while(getline(file, line)) {
        if (line.empty()) continue;
        switch (line[0]) {
            case 'Q':
                question.setText(line.substr(2));
                answers.clear();
                break;
            case 'A':
                answers.push_back(Answer(line.substr(2)));
                break;
            default:
                istringstream iss(line);
                int inte;
                while (iss >> inte) {
                    answers[inte - 1].setCorrect(true);
                }
                question.setAnswers(answers);
                questions.push_back(question);
        }
    }

    srand(time(NULL));
    unsigned seed = rand();
    shuffle(this->questions.begin(), this->questions.end(), default_random_engine(seed));

    for (int i = 0; i < this->questions.size(); ++i) {
        this->questions[i].randomizeAnswers();
    }

    file.close();
}

void Quiz::printQuestions() {
    for (int i = 0; i < getNumQuestion(); ++i) {
        cout <<i+1 << ". question: " << getQuestion(i).getText() << endl;
        for (int j = 0; j < getQuestion(i).getAnswers().size(); ++j) {
            cout << setw(6) <<j+1 << ". answer: " << getQuestion(i).getAnswers()[j].getText() << " (" << (getQuestion(
                    i).getAnswers()[j].isCorrect() ? "correct" : "incorrect") << ")" << endl;
        }
    }
}
