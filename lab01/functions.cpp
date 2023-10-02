
#include <cmath>
#include "functions.h"
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

int countBits(int number) {
    int count = 0;

    while (number) {
        count += number & 1;
        number >>=1;
    }

    return count;
}

double mean(double array[], int numElements) {

    if(numElements == 0) {
        return NAN;
    } else {
        double sum = 0;

        for(int i = 0; i < numElements; i++) {
            sum += array[i];
        }

        return sum / numElements;
    }
}

double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    } else {
        double avg = 0;
        double stDev = 0;

        for (int i = 0; i < numElements; ++i) {
            avg += array[i];
        }

        avg /= numElements;

        for (int i = 0; i< numElements; i++) {
            stDev += (array[i] - avg) * (array[i] - avg);
        }

        stDev /= numElements;

        return stDev;
    }
}

pair<double, double> max2(double array[], int numElements) {
    pair <double, double> maxi;

    maxi.first = 0;
    maxi.second = 0;

    if(numElements == 0) {
        maxi.first = NAN;
        maxi.second = NAN;
    } else if (numElements == 1) {
        maxi.first = array[0];
        maxi.second = array[0];
    } else {
        sort(array, array + numElements);
        maxi.first = array[numElements-2];
        maxi.second = array[numElements-1];
    }

    return maxi;
}

int countWords(string text) {
    istringstream iss(text);

    string word;
    int count = 0;

    while(iss >> word) {
        cout << word;
        count++;
    }

    return count;
}

string code(string text) {
    for (int i = 0; i < text.size(); ++i) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            text[i] = text[i] + 1;
        }
    }

    return text;
}

string decode(string text) {
    for (int i = 0; i < text.size(); ++i) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            text[i] = text[i] - 1;
        }
    }

    return text;
}

string capitalizeWords(string text) {

    bool firstChar = true;

    string newText = "";

    for (int i = 0; i < text[i]; ++i) {
        if (isalpha(text[i])) {
            if(firstChar) {
                newText += toupper(text[i]);
                firstChar = false;
            } else {
                newText += tolower(text[i]);
            }
        } else if (text[i]== ' ') {
            newText += text[i];
            firstChar = true;
        } else {
            newText += text[i];
        }

    }

    return newText;
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}



