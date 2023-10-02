#include <iostream>
#include "functions.h"
#include <sstream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {

    //First part - 1st ex.
    /*int n = 0;
    cout << "Enter a number: ";
    cin >> n;

    cout<<"The number of bits in " << n << " is " << countBits(n) << endl;*/

    //First part - 3rd ex. with numbers
   /* cout << "Test mean function" << endl;

    double array[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The mean of the array is: "<< mean(array, numElements)<<endl;*/

    //First part - 3rd ex. without numbers
    /* cout << "Test mean function" << endl;

    double array[] = {};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The mean of the array is: "<< mean(array, numElements)<<endl;*/

    //First part - 4th ex. with numbers
    /*cout << "Test stDev function" << endl;

    double array[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The stDev of the array is: "<< stddev(array, numElements)<<endl;*/

    //First part - 4th ex. without numbers
    /*cout << "Test stDev function" << endl;

    double array[] = {};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The stDev of the array is: "<< stddev(array, numElements)<<endl;*/

    //First part - 5th ex. with numbers
    /*cout << "Test pair structure function" << endl;
    double array[] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The two maximum number of the array is: " << max2(array, numElements).first << " and " << max2(array, numElements).second << endl;*/

    //First part - 5th ex. without numbers
    /*cout << "Test pair structure function" << endl;
    double array[] = {};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The two maximum number of the array is: " << max2(array, numElements).first << " and " << max2(array, numElements).second << endl;*/

    //First part - 5th ex. with only one number
    /*cout << "Test pair structure function" << endl;
    double array[] = {2.0};

    int numElements = sizeof(array) / sizeof(array[0]);

    cout<<"The two maximum number of the array is: " << max2(array, numElements).first << " and " << max2(array, numElements).second << endl;*/

    //Second part - 1st ex.
    /*double sum = 0;

    for (int i = 0; i < argc; ++i) {
        istringstream iss(argv[i]);

        double val = 0;

        iss >> val;

        if(!iss) {
            cout<<"Argument " << i << " is not numeric " << argv[i] << endl;
        }

        sum += val;
    }

    cout << "The sum of numeric arguments: " << sum << endl;*/

    //Second part - 2nd ex. with words
    /*string testText = "One two three";

    cout << "In " << testText << " text contains " << countWords(testText) << " words!";*/

    //Second part - 2nd ex. without words
    /*string testText = "";

    cout << "In " << testText << " text contains " << countWords(testText) << " words!";*/

    //Second part - 3rd ex. encoding
    /*    string testText = "The apple is red";

        cout<<"The converted text is: " << code(testText) << endl;*/

    //Second part - 3rd ex. decoding
    /*string testText = "Uif bqqmf jt sfe";

    cout<<"The deconverted text is: " << decode(testText) << endl;*/

    //Second part - 4th ex.
    /*string outText = "";

    cout<<"Please enter a string: "<<endl;
    getline(cin, outText);
    cout<<"The transformated text is: " << capitalizeWords(outText)<<endl;*/

    //Bible extra exercise

    string fileName = argv[1];
    int n = stoi(argv[2]);

    cout<<"The filename is: " << fileName<<endl;

    ifstream file(fileName);

    if(!file) {
        cout<<"Error when opening the file!"<<endl;
    }

    map <string, int> countWords;
    string actualWord;

    while(file >> actualWord) {
        //Remove the punctuation mark from the word
        for (int i = 0; i < actualWord.size(); ++i) {
            if(actualWord[i] == '.' || actualWord[i] == ',' || actualWord[i] == '!' || actualWord[i] == '?' || actualWord[i] == ':' || actualWord[i] == ';'  || actualWord[i] == '(' || actualWord[i] == ')' || actualWord[i] == '{' || actualWord[i] == '}' || actualWord[i] == '[' || actualWord[i] == ']') {
                actualWord.erase(i, 1);
            }
        }
        ++countWords[actualWord];
    }

    file.close();

    /*for (auto it = countWords.cbegin(); it != countWords.cend(); ++it) {
        cout<<it->first<<" = " << it->second << endl;
    }*/

    vector<pair<int, int> > A;

    // Copy key-value pair from Map to vector of pairs
    for (auto& it : cou) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);

    // Print the sorted value
    cout << "The map, sorted by value is: \n";
    for (auto& it : A) {

        cout << it.first << ' '
             << it.second << '\n';
    }

    for (auto it = countWords.cbegin(); it != countWords.cend(); ++it) {
        cout<<it->first<<" = " << it->second << endl;
    }


    return 0;
}
