/*
 * The ChildrenBook class represents a children book item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to children books, such as author and title
 */

#include <childrenbook.h>
#include "book.h"
#include "item.h"
#include <string>
using namespace std;

//---------------------------------------------------------------------------
// ChildrenBook
// Constructor
ChildrenBook::ChildrenBook()
    : Book()
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// ChildrenBook
// Constructor, setting corresponding data members
ChildrenBook::ChildrenBook(string author, string title, int year)
    : Book(), authorName(author), title(title), year(year)
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int ChildrenBook::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// countCheckedOut
// Counts checked out count for given book
int ChildrenBook::countCheckedOut() const
{
    return checkedOut;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
void ChildrenBook::checkOut()
{
    available--;
    checkedOut++;
}

//---------------------------------------------------------------------------
// returnBook
// Returns this book for a given user in a given library
void ChildrenBook::returnBook()
{
    available++;
    checkedOut--;
}

//---------------------------------------------------------------------------
// operator
// Overloaded comparison operators
bool ChildrenBook::operator==(const Item &other) const
{
    const ChildrenBook &otherChildrenBook =
        static_cast<const ChildrenBook &>(other);
    return (authorName == otherChildrenBook.authorName &&
            title == otherChildrenBook.title && year == otherChildrenBook.year);
}

bool ChildrenBook::operator!=(const Item &other) const
{
    return !(*this == other);
}

bool ChildrenBook::operator<(const Item &other) const
{
    const ChildrenBook &otherChildrenBook =
        static_cast<const ChildrenBook &>(other);
    if (title == otherChildrenBook.title)
    {
        return authorName < otherChildrenBook.authorName;
    }
    else
    {
        return title < otherChildrenBook.title;
    }
}

bool ChildrenBook::operator>(const Item &other) const
{
    const ChildrenBook &otherChildrenBook =
        static_cast<const ChildrenBook &>(other);
    if (title == otherChildrenBook.title)
    {
        return authorName > otherChildrenBook.authorName;
    }
    else
    {
        return title > otherChildrenBook.title;
    }
}

bool ChildrenBook::operator>=(const Item &other) const
{
    return (*this == other || *this > other);
}

bool ChildrenBook::operator<=(const Item &other) const
{
    return (*this == other || *this < other);
}