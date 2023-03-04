/*
 * The Fiction class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 */

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include <string>
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
    int countAvailable() const;

    // Checks checked out count for given book
    int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    void checkOut();

    // Returns this book for a given user in a given library
    void returnItem();

    // Allows item factory to create a fiction object
    virtual Item *create() const;

    virtual void setData(ifstream &inputFile);

    // Overloaded output operator
    // virtual ostream &operator<<(ostream &output, const Item &item) const;

    // Overloaded comparison operators
    bool operator<(const Item &other) const;
    bool operator>(const Item &other) const;
    bool operator>=(const Item &other) const;
    bool operator<=(const Item &other) const;
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
};

#endif