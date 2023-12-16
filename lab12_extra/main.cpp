#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

int main() {
    map<string, set<int>> stat;

    ifstream file("bemenet.txt");

    if(!file){
        cout<<"File not found"<<endl;
        exit(1);
    }

    string indexedString;

    while(getline(file, indexedString)){
        if(indexedString.length() == 0){
            break;
        }
        stat.insert({indexedString, set<int>()});
    }

    string actualRow;
    int i = 1;

    while(getline(file, actualRow)){
        for(auto &x : stat){
            for (char &c : actualRow) {
                c = tolower(c);
            }

            istringstream iss(actualRow);
            string word;
            while(iss >> word){
                regex pattern("[^[:alpha:]]");
                word = regex_replace(word, pattern, "");

                if(word == x.first){
                    x.second.insert(i);
                }
            }

        }
        i++;
    }

    for(auto &x : stat){
        cout<<x.first<<" ";
        vector<int> v;

        for (auto &y : x.second) {
            v.push_back(y);
        }

        for (int j = 0; j < v.size(); ++j) {
            cout<<v[j];
            bool isOk = false;

            for (int k = j + 1; k < v.size(); ++k) {
                if(v[k] - v[j] == 1){
                    isOk = true;

                    while(v[k] - v[j] == 1){
                        j++;
                        k++;
                    }

                }
                if (isOk){
                    cout<<"-"<<v[k - 1];
                    isOk = false;
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }

    file.close();

    return 0;
}
