#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {
    /*Book book1("J. K. Rowling", "Harry Potter 1", 1998, 287);
    Book book3("J. K. Rowling", "Harry Potter 2", 2000, 318);
    Book book2("J. K. Rowling", "Harry Potter 3", 2003, 299);

    *//*cout<<book1<<endl;
    cout<<book2<<endl;
    cout<<book3<<endl;*//*

    Library library1("First library", 200);

    library1.addBook(book1);
    library1.addBook(book2);
    library1.addBook(book3);

    library1.printBooks();

    string searchTerm = "Harry Potter 2";

    cout<<"The book which are found: "<<library1.findBook(searchTerm)<<endl;

    string searchAuthor = "J. K. Rowling";
    cout<<library1.countAuthor(searchAuthor)<<"x books found"<<endl;

    library1.removeBook("J. K. Rowling");

    cout<<"After deletion:"<<endl;
    library1.printBooks();*/

    Library library2("Second library", 150);

    Book book1("Jokai Mor", "Egri csillagok", 1980, 300);
    Book book2("Jokai Mor", "A koszivu ember fiai", 1967, 400);
    Book book3("Murakami Haruki", "Sotetedes utan", 2004, 250);
    Book book4("Murakami Haruki", "A norveg erdo", 1987, 420);
    Book book5("Murakami Haruki", "1Q84", 1987, 800);
    Book book6("Knausgard Karl Ove", "Harcom", 2009, 1000);

    library2.addBook(book1);
    library2.addBook(book2);
    library2.addBook(book3);
    library2.addBook(book4);
    library2.addBook(book5);
    library2.addBook(book6);

    library2.printBooks();

    string searchedAuthor  = "Murakami Haruki";

    cout<<searchedAuthor<<" has " <<library2.countAuthor(searchedAuthor)<<" books in the library"<<endl;

    string searchTitle = "A koszivu ember fiai";

    cout<<"The searched title: " << searchTitle<<endl;
     cout<<library2.findBook(searchTitle)<<endl;

     library2.sortLibrary();
     cout<<"After the sort the library is:"<<endl;
     library2.printBooks();

     library2.removeBook(book2);
     cout<<"After the deletion the library: "<<endl;
     library2.printBooks();


    return 0;
}
