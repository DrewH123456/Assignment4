/*
 * The ChildrenBook class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 *
 */

#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include "book.h"
#include "item.h"

class ChildrenBook : public Book
{
    // friend ostream &operator<<(ostream &output, const ChildrenBook c);

protected:
    string authorName;
    string title;
    int year;

public:
    // Constructor, setting corresponding data members
    ChildrenBook(string author, string title, int year);

    // Destructor
    virtual ~ChildrenBook();

    // Counts available copies
    int countAvailable() const;

    // Checks checked out count for given book
    int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    void checkOut();

    // Returns this book for a given user in a given library
    void returnBook();

    // Overloaded comparison operators
    // pointer or object???
    bool operator<(const Item &other) const;
    bool operator>(const Item &other) const;
    bool operator>=(const Item &other) const;
    bool operator>=(const Item &other) const;
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
};

#endif