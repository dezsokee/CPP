#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    ///exercise nr.1
    cout<<"Exercise 1"<<endl;
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};

    auto it = find_if(fruits.begin(), fruits.end(), [fruits](const string &item) {
        return (item.find("berry") != std::string::npos);
    });

    if(it != fruits.end()) {
        cout<<"Contains"<<endl;
    } else {
        cout<<"Not contains"<<endl;
    }

    ///exercise nr.2
    cout<<"Exercise 2"<<endl;
    vector<int> numbers {0, 0, 0, 0};

    cout<<"The numbers vector: ";
    for (const auto &item : numbers) {
        cout<<item<<" ";
    }
    cout<<endl;

    if(all_of(numbers.begin(), numbers.end(), [numbers] (const auto &item) {
       return item == 0;
    })
    == 1) {
        cout<<"All of the numbers are zeros!"<<endl;
    } else {
        cout<<"The numbers vector contains values which is not zero!"<<endl;
    }

    ///exercise nr.3
    cout<<"Exercise 3"<<endl;
    vector<int> numbers2 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"The original numbers2 vector: ";
    for (const auto &item : numbers2) {
        cout<<item<<" ";
    }
    cout<<endl;

    for_each(numbers2.begin(), numbers2.end(), [&fruits] (int &item) {
        item = item * 2;
    });

    cout<<"After the duplication: ";
    for (const auto &item : numbers2) {
        cout<<item<<" ";
    }
    cout<<endl;

    ///exercise nr.4
    cout<<"Exercise 4"<<endl;

    int sum = 0;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    for_each(months.begin(), months.end(), [months, &sum] (const string &item) {
        if(item.length() == 5)
            sum +=1;
    });

    cout<<"The number of months which contains exactly 5 character is: "<<sum<<endl;

    ///exercise nr.5
    cout<<"Exercise 5"<<endl;

    vector<double> numbers3 {1.1, 6.12, 8.6, 1.531, 52.2};

    cout<<"The original numbers3 vector: ";
    for (const auto &item : numbers3) {
        cout<<item<<" ";
    }
    cout<<endl;

    sort(numbers3.begin(), numbers3.end(), [&numbers] (const double &item1, const double &item2) {
        return item1 < item2;
    });

    cout<<"The numbers3 vector after the sort method: ";
    for (const auto &item : numbers3) {
        cout<<item<<" ";
    }
    cout<<endl;

    ///exercise nr.6
    cout<<"Exercise 6"<<endl;

    vector<pair<string, int>> months_with_temp {
            make_pair("January", -1),
            make_pair("February",2),
            make_pair("March", 5),
            make_pair("April", 7),
            make_pair("May", 15),
            make_pair("June", 20),
            make_pair("July", 22),
            make_pair("August", 30),
            make_pair("September", 14),
            make_pair("October", 10),
            make_pair("November", 0),
            make_pair("December", -3),
    };

    cout<<"The original months with temperatures"<<endl;
    for(const auto &item : months_with_temp) {
        cout<<item.first<<" "<<item.second<<endl;
    }
    cout<<endl;

    sort(months_with_temp.begin(), months_with_temp.end(), [months] (const pair<string, int> &item1, const pair<string, int> &item2) {
        return item1.second < item2.second;
    });

    cout<<"After sorting the months are:"<<endl;
    for(const auto &item : months_with_temp) {
        cout<<item.first<<" "<<item.second<<endl;
    }
    cout<<endl;

    ///exercise nr.7
    cout<<"Exercise 7"<<endl;

    vector<double> numbers4 {-1.5, 8.3, -6.1, -10.8};

    cout<<"The original numbers4 vector:"<<endl;
    for(const auto &item : numbers4) {
        cout<<item<<" ";
    }
    cout<<endl;

    sort(numbers4.begin(), numbers4.end(), [numbers4] (const double &item1, const double &item2) {
        return abs(item1) < abs(item2);
    });

    cout<<"After sorting the numbers4 vector with abs values:"<<endl;
    for(const auto &item : numbers4) {
        cout<<item<<" ";
    }

    ///exercise nr.8
    cout<<"Exercise 8"<<endl;

    for_each(months.begin(), months.end(), [&months] (string &item) {
        transform(item.begin(), item.end(), item.begin(), ::tolower);
    });

    cout<<"After tolower functions in months vector:"<<endl;
    for(const auto &item : months) {
        cout<<item<<" ";
    }
    cout<<endl;

    ///exercise nr.9
    cout<<"Exercise 9"<<endl;

    vector<char> abc {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };

    cout<<"The original abc vector:"<<endl;
    for(const auto &item : abc) {
        cout<<item<<" ";
    }
    cout<<endl;

    unsigned seed = 0;

    shuffle(abc.begin(), abc.end(), default_random_engine(seed));

    string string_abc = "";

    for (char i : abc) {
        string_abc.push_back(i);
    }

    cout<<string_abc<<endl;

    cout<<"The abc vector after the shuffle:"<<endl;
    for(const auto &item : abc) {
        cout<<item<<" ";
    }
    cout<<endl;

    sort(months.begin(), months.end(), [&months, string_abc] (string &item1, string &item2) {
        // Find the positions of the months in the ABC system
        auto index1 = string_abc.find(item1[0]);
        auto index2 = string_abc.find(item2[0]);

        // Compare the indices to determine the order
        return index1 < index2;
    });

    cout<<"The months vector after the sort:"<<endl;
    for(const auto &item : months) {
        cout<<item<<" ";
    }
    cout<<endl;

    return 0;
}