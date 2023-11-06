#include <iomanip>
#include "QuizGame.h"

void QuizGame::play() {
    cout<<"Welcome " << user.getName() << "!"<<endl;

    cout<<"The quiz has started!"<<endl<<endl;
    int count = 0;

    for (int i = 0; i < quiz.getNumQuestion(); ++i) {
        cout<<i+1 << ". question:"<<getQuiz().getQuestions()[i].getText()<<endl;
        cout<<setw(6)<<"The answers are:"<<endl;
        for (int j = 0; j < getQuiz().getQuestions()[i].getAnswers().size(); ++j) {
            cout<<setw(6)<<j+1<<". answer: "<<getQuiz().getQuestions()[i].getAnswers()[j].getText()<<endl;
        }

        cout<<"Which answers are correct?"<<endl;
        string answer;
        getline(cin, answer);

        int answerNumber;
        vector<int> answerNumbers;
        istringstream iss(answer);

        while (iss >> answerNumber) {
            if (answerNumber < 1 || answerNumber > getQuiz().getQuestions()[i].getAnswers().size()) {
                cout<<"Invalid answer number!"<<endl;
                continue;
            }
            answerNumbers.push_back(answerNumber);
        }

        vector<int> comparedAnswers;
        bool ok = true;
        for(int j = 0; j < getQuiz().getQuestions()[i].getAnswers().size(); j++) {
            if(getQuiz().getQuestions()[i].getAnswers()[j].isCorrect()) {
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
            count++;
        } else {
            cout<<"Incorrect answer!"<<endl;
        }
    }

    cout<<"Your score is: "<<count<<"/"<<quiz.getNumQuestion()<<endl;
    score = count;
    user.addScore(this->quiz.getName(), count);
}
