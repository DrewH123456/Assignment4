/*
 * The Fiction class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 */

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
// #include "item.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Fiction : public Book
{
protected:
    string authorName;
    string title;
    int year;

public:
    // Constructor
    Fiction();

    // Destructor
    virtual ~Fiction();

    // Counts available copies
    virtual int countAvailable() const;

    // Checks checked out count for given book
    virtual int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    virtual void checkOut();

    // Returns this book for a given user in a given library
    virtual void returnItem();

    // Allows item factory to create a fiction object
    virtual Item *create() const;

    // sets item's data using info from line in infile from data4books.txt
    virtual void setData(ifstream &inputFile);

    // sets item's data using info from line in infile from data4commands.txt
    virtual void setDataCommand(ifstream &inputFile);

    // prints book's description
    virtual void print(ostream &out) const;

    // Overloaded output operator
    // virtual ostream &operator<<(ostream &output, const Item &item) const;

    // Overloaded comparison operators
    virtual bool operator<(const Item &other) const;
    virtual bool operator>(const Item &other) const;
    virtual bool operator>=(const Item &other) const;
    virtual bool operator<=(const Item &other) const;
    virtual bool operator==(const Item &other) const;
    virtual bool operator!=(const Item &other) const;
};
#endif