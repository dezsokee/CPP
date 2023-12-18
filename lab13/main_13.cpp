#include <iostream>
#include "SimpleTextGenerator.h"

using namespace std;

int main() {

    SimpleTextGenerator simpleTextGenerator;

    simpleTextGenerator.trainFromText("Now is not the time for sleep, now is the time for party!");
    simpleTextGenerator.printMap();

    SimpleTextGenerator simpleTextGenerator2;

    simpleTextGenerator2.trainFromFile("bible.txt");
    simpleTextGenerator2.printMap();

    for (int i = 0; i < 3; ++i) {
        cout << "Generated text: " << simpleTextGenerator.generate("now is", 6) << endl;
    }

    return 0;
}