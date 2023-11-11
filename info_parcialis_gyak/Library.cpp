#include <algorithm>
#include "Library.h"

Library::Library(const string &libraryName, const int &capacity) {
    this->libraryName = libraryName;
    this->capacity = capacity;
}

const string &Library::getLibraryName() const {
    return libraryName;
}

const vector<Book> &Library::getBooks() const {
    return books;
}

int Library::getCapacity() const {
    return capacity;
}

void Library::addBook(const Book &newBook) {
    if(books.size() < capacity) {
        books.push_back(newBook);
    } else {
        throw invalid_argument("Library is full!");
    }
}

void Library::printBooks() {
    cout<<"The books in the library "<<libraryName<<" are:"<<endl;
    for (int i = 0; i < books.size(); ++i) {
        cout<<books[i];
    }
}

const Book Library::findBook(const string &searchTerm) {
    for (int i = 0; i < books.size(); ++i) {
        if(books[i].getTitle() == searchTerm || books[i].getAuthor() == searchTerm) {
            return books[i];
        }
    }
}

const int Library::countAuthor(const string &author) {
    int count = 0;

    for (int i = 0; i < books.size(); ++i) {
        if(books[i].getAuthor() == author) {
            count++;
        }
    }

    return count;
}

void Library::removeBook(const Book& book) {
    for (int i = 0; i < books.size(); ++i) {
        if(books[i] ==  book) {
            books.erase(books.begin() + i);
            break;
        }
    }
}

int cmp(const Book &a, const Book &b) {
    if(a.getAuthor() > b.getAuthor()) {
        return 1;
    } else if (a.getAuthor() < b.getAuthor()) {
        return -1;
    } else if (a.getAuthor() == b.getAuthor()) {
        if (a.getYear() > b.getYear()) {
            return 1;
        } else if (a.getYear() < b.getYear()) {
            return -1;
        } else {
            return 0;
        }
    }
}

void Library::sortLibrary() {
    sort(books.begin(), books.end(), cmp);
}
