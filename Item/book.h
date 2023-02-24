/**
 * The Book class represents a collection of a given book in the library system.
 * It contains information about the book's author, title,
 * year of publication, and the number of checked out/available books
 * The Book class serves as the parent class for more specific
 * book types, such as ChildrenBook, FictionBook, and Periodical.
 */
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
protected:
    string author;
    string title;
    int year;
    int month;
    int available;
    int checkedOut;
    vector<User *> users;

public:
    // Pure virtual default constructor
    virtual Book() = 0;

    // Pure virtual constructor, setting corresponding data member
    virtual Book(const string &author, const string &title, int year,
                 int available) = 0;

    // Destructor
    virtual ~Book();

    // Checks available count for given book
    virtual int countAvailable() const = 0;

    // Checks checked out count for given book
    virtual int countCheckedOut() const = 0;

    // Checks out this book for a given user in a given library
    virtual void checkOut() = 0;

    // Returns this book for a given user in a given library
    virtual void returnBook() = 0;
};

#endif