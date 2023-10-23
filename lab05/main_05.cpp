#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Quiz.h"

using namespace std;

int main() {
    Quiz quiz("Elso kviz", "data.txt");

    cout<<"The quiz has started!"<<endl<<endl;
    for (int i = 0; i < quiz.getNumQuestion(); ++i) {
        cout<<i+1 << ". question:"<<quiz.getQuestions()[i].getText()<<endl;
        cout<<setw(6)<<"The answers are:"<<endl;
        for (int j = 0; j < quiz.getQuestions()[i].getAnswers().size(); ++j) {
            cout<<setw(6)<<j+1<<". answer: "<<quiz.getQuestions()[i].getAnswers()[j].getText()<<endl;
        }

        cout<<"Tell me the number of the correct answers!"<<endl;
        string answer;
        getline(cin, answer);

        int answerNumber;
        vector<int> answerNumbers;
        istringstream iss(answer);
        
        while (iss >> answerNumber) {
            if (answerNumber < 1 || answerNumber > quiz.getQuestions()[i].getAnswers().size()) {
                cout<<"Invalid answer number!"<<endl;
                continue;
            }
            answerNumbers.push_back(answerNumber);
        }

        vector<int> comparedAnswers;
        bool ok = true;
        for(int j = 0; j < quiz.getQuestions()[i].getAnswers().size(); j++) {
            if(quiz.getQuestions()[i].getAnswers()[j].isCorrect()) {
                comparedAnswers.push_back(j+1);
            }
        }

        sort(comparedAnswers.begin(), comparedAnswers.end());
        sort(answerNumbers.begin(), answerNumbers.end());

        if(comparedAnswers.size() != answerNumbers.size()) {
            ok = false;
        } else {
            for (int j = 0; j < comparedAnswers.size(); ++j) {
                if(comparedAnswers[j] != answerNumbers[j]) {
                    ok = false;
                }
            }
        }

        if(ok) {
            cout<<"Correct answer!"<<endl;
        } else {
            cout<<"Incorrect answer!"<<endl;
        }
    }

    return 0;
}