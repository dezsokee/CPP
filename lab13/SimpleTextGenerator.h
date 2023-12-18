#ifndef LAB13_SIMPLETEXTGENERATOR_H
#define LAB13_SIMPLETEXTGENERATOR_H


#include <vector>
#include <map>
#include "TextGenerator.h"
#include <set>

class SimpleTextGenerator : public TextGenerator {
private:
    map<string, set<string>> wordMap;
public:
    virtual void trainFromText(string trainingText) override;

    virtual void trainFromFile(string filename) override;

    virtual string generate(string startWords, int numWords=10) override;

    void printMap();
};


#endif //LAB13_SIMPLETEXTGENERATOR_H
