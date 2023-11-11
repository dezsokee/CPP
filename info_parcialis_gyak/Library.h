#ifndef INFO_PARCIALIS_GYAK_LIBRARY_H
#define INFO_PARCIALIS_GYAK_LIBRARY_H

#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class Library {
    string libraryName;
    vector<Book> books;
    int capacity;
public:
    Library(const string &libraryName, const int &capacity);

    const string &getLibraryName() const;

    const vector<Book> &getBooks() const;

    int getCapacity() const;

    void addBook(const Book &newBook);

    void printBooks();

    const Book findBook(const string& searchTerm);

    const int countAuthor(const string &author);

    void removeBook(const Book& book);

    void sortLibrary();
};


#endif //INFO_PARCIALIS_GYAK_LIBRARY_H
