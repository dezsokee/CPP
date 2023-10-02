#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

#include <string>
#include <map>

using namespace std;

int countBits(int number);

double mean(double array[], int numElements);

bool setBit(int& number, int order);

double stddev(double array[], int numElements);

pair<double, double> max2(double array[], int numElements);

int countWords(string text);

string code(string text);

string decode(string text);

string capitalizeWords(string text);

string cleanWord(string word);

void sortMap(map<string, int>& M, int n);

void printMap(map<string, int>& M);

#endif //CPP_2022_FUNCTIONS_H
