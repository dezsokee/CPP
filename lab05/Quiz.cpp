#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
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
    file.close();
}

void Quiz::printQuestions() {
    for (int i = 0; i < getNumQuestion(); ++i) {
        cout<<i+1<<". question: "<<getQuestions(i).getText()<<endl;
        for (int j = 0; j < getQuestions(i).getAnswers().size(); ++j) {
            cout<<setw(6)<<j+1<<". answer: "<<getQuestions(i).getAnswers()[j].getText()<< " ("<< (getQuestions(i).getAnswers()[j].isCorrect() ? "correct" : "incorrect") <<")"<<endl;
        }
    }
}
