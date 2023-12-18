#include <sstream>
#include <fstream>
#include <random>
#include "SimpleTextGenerator.h"

string cleanWord(string word) {
    string cleanWord = "";

    for(int i = 0; i < word.length(); i++) {
        if(isalpha(word[i])) {
            cleanWord += word[i];
        }
    }

    return cleanWord;
}

string toLower(string word) {
    string lowerWord = "";

    for(int i = 0; i < word.length(); i++) {
        lowerWord += tolower(word[i]);
    }

    return lowerWord;
}

void SimpleTextGenerator::printMap() {
    for(auto it = wordMap.begin(); it != wordMap.end(); it++) {
        cout<<it->first<<": ";

        for (const auto &i : it->second) {
            cout<<i<<" ";
        }

        cout<<endl;
    }
}

int countWords (string text) {
    int wordCount = 0;

    for(int i = 0; i < text.length(); i++) {
        if(text[i] == ' ') {
            wordCount++;
        }
    }

    return wordCount;
}

void SimpleTextGenerator::trainFromText(string trainingText) {
    istringstream iss(trainingText);

    string word;
    string nextWord;
    string nextNextWord;
    string key;
    int i = 0;

    while(i != countWords(trainingText) - 1) {

        if (i == 0) {
            iss >> word >> nextWord;
        }

        iss >> nextNextWord;

        word = cleanWord(word);
        nextWord = cleanWord(nextWord);
        nextNextWord = cleanWord(nextNextWord);

        word = toLower(word);
        nextWord = toLower(nextWord);
        nextNextWord = toLower(nextNextWord);

        key = word + " " + nextWord;
        wordMap[key].insert(nextNextWord);

        word = nextWord;
        nextWord = nextNextWord;
        i++;

    }
    key = word + " " + nextWord;
    wordMap[key].insert("");
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout<<"Couldn't open the specific file!"<<endl;
        exit(1);
    }

    string trainingText((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());


    istringstream iss(trainingText);
    string word;
    string nextWord;
    string nextNextWord;
    string key;
    int i = 0;

    while(i != countWords(trainingText) - 1) {

        if (i == 0) {
            iss >> word >> nextWord;
        }

        iss >> nextNextWord;

        word = cleanWord(word);
        nextWord = cleanWord(nextWord);
        nextNextWord = cleanWord(nextNextWord);

        word = toLower(word);
        nextWord = toLower(nextWord);
        nextNextWord = toLower(nextNextWord);

        key = word + " " + nextWord;
        wordMap[key].insert(nextNextWord);

        word = nextWord;
        nextWord = nextNextWord;
        i++;

    }
    key = word + " " + nextWord;
    wordMap[key].insert("");
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    string generatedString = startWords;

    srand(time(NULL));

    for (int i = 0; i < numWords; i++) {
        auto iter = wordMap.find(startWords);

        if (iter != wordMap.end() && !iter->second.empty()) {
            random_device rd;
            mt19937 gen(rd());
            auto randomIterator = next(begin(iter->second),uniform_int_distribution<>(0, iter->second.size() - 1)(gen));

            string randomElement = *randomIterator;

            generatedString += " " + randomElement;

            startWords = startWords.substr(startWords.find(' ') + 1) + " " + randomElement;
        } else {
            break;
        }
    }

    return generatedString;
}
