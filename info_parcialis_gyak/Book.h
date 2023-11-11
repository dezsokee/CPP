#ifndef INFO_PARCIALIS_GYAK_BOOK_H
#define INFO_PARCIALIS_GYAK_BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
    string author;
    string title;
    int year;
    int pages;
public:
    Book(string author, string title, int year, int pages);

    const string &getAuthor() const;

    const string &getTitle() const;

    int getYear() const;

    int getPages() const;

    void print(ostream &os);

    friend ostream &operator<<(ostream &os, const Book &book);

    bool operator==(const Book &book1);
};


#endif //INFO_PARCIALIS_GYAK_BOOK_H
