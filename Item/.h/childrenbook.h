/*
 * The ChildrenBook class represents a children book item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to children books, such as author and title
 */

#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include "book.h"
#include "item.h"

class ChildrenBook : public Book
{
protected:
    string authorName;
    string title;
    int year;

public:
    // Constructor
    ChildrenBook();

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
    void returnItem();

    // Allows item factory to create a children book object
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