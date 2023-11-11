#include "Book.h"

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return year;
}

int Book::getPages() const {
    return pages;
}

ostream &operator<<(ostream &os, const Book &book) {
    os<<book.getTitle()<<" by "<<book.getAuthor()<<" released in "<<book.getYear()<<" has "<<book.getPages()<<" pages"<<endl;
    return os;
}

Book::Book(string author, string title, int year, int pages) {
    this->author = author;
    this->title = title;
    this->year = year;
    this->pages = pages;
}

bool Book::operator==(const Book &book1) {
    if(this->title == book1.getTitle() && this->author == book1.getAuthor())
        return true;
    return false;
}

