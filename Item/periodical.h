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
private:
public:
    // Constructor
    Periodical();

    // Constructor, setting corresponding data member
    Periodical(const string &author, const string &title, int year,
               int available)

        // Destructor
        virtual ~Periodical()
    {
    }

    // Counts available copies
    int countAvailable const();

    // Checks checked out count for given book
    int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    void checkOut();

    // Returns this book for a given user in a given library
    void returnBook();

    // Overloaded comparison operators
    bool operator<(const Periodical &other) const;
    bool operator>(const Periodical &other) const;
    bool operator>=(const Periodical &other) const;
    bool operator>=(const Periodical &other) const;
    bool operator==(const Periodical &other) const;
    bool operator!=(const Periodical &other) const;
};

#endif