#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Quiz.h"
#include "QuizGame.h"

using namespace std;

int main() {
    User users[] = {User("Peter"), User("Kati")};

    Quiz quizzes[] = {Quiz("The first C++ quiz", "cpp1.txt"), Quiz("The second C++ quiz", "cpp2.txt")};

    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);

    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.play();
            cout << "Name: " << game.getUser().getName() << ", score: " <<
                 game.getScore() << endl << endl;
        }
    }

    cout << endl << "****************" << endl;
    cout << "User's results:" << endl;
    for (int i = 0; i < num_users; ++i) {
        cout << users[i] << endl;
    }
    cout << "****************" << endl;

    return 0;
}