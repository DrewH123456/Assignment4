/*
 * The ChildrenBook class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 *
 */

#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H
#include "book.h"

class ChildrenBook : public Book
{
    // friend ostream &operator<<(ostream &output, const ChildrenBook c);
private:
public:
    // Constructor
    ChildrenBook();

    // Constructor, setting corresponding data member
    ChildrenBook(const string &author, const string &title, int year,
                 int available);

    // Destructor
    virtual ~ChildrenBook();

    // Counts available copies
    int countAvailable const();

    // Checks checked out count for given book
    int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    void checkOut();

    // Returns this book for a given user in a given library
    void returnBook();

    // Overloaded comparison operators
    bool operator<(const ChildrenBook &other) const;
    bool operator>(const ChildrenBook &other) const;
    bool operator>=(const ChildrenBook &other) const;
    bool operator>=(const ChildrenBook &other) const;
    bool operator==(const ChildrenBook &other) const;
    bool operator!=(const ChildrenBook &other) const;
};

#endif