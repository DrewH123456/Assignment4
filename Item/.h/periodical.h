/*
 * The Periodical class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 */

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"

class Periodical : public Book
{
protected:
    int year;
    int month;
    string title;

public:
    // Constructor
    Periodical();

    // Constructor, setting corresponding data members
    Periodical(string title, int month, int year);

    // Destructor
    virtual ~Periodical();

    // Counts available copies
    int countAvailable() const;

    // Checks checked out count for given book
    int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    void checkOut();

    // Returns this book for a given user in a given library
    void returnItem();

    // Allows item factory to create a periodical object
    virtual Item *create() const;

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