/*
 * The Fiction class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 */

#include "fiction.h"
#include "book.h"
#include "item.h"
#include <string>
using namespace std;

//---------------------------------------------------------------------------
// Fiction
// Constructor
Fiction::Fiction() : Book()
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// Fiction
// Constructor, setting corresponding data members
Fiction::Fiction(string author, string title, int year) : Book(), authorName(author), title(title), year(year)
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int Fiction::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// countCheckedOut
// Counts checked out count for given book
int Fiction::countCheckedOut() const
{
    return checkedOut;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
void Fiction::checkOut()
{
    available--;
    checkedOut++;
}

//---------------------------------------------------------------------------
// returnBook
// Returns this book for a given user in a given library
void Fiction::returnItem()
{
    available++;
    checkedOut--;
}

//---------------------------------------------------------------------------
// create
// Allows item factory to create a fiction object
Item *Fiction::create() const
{
    return new Fiction();
}

//---------------------------------------------------------------------------
// operator
// Overloaded comparison operators
bool Fiction::operator==(const Item &other) const
{
    const Fiction &otherFiction = static_cast<const Fiction &>(other);
    return (authorName == otherFiction.authorName &&
            title == otherFiction.title && year == otherFiction.year);
}

bool Fiction::operator!=(const Item &other) const
{
    return !(*this == other);
}

bool Fiction::operator<(const Item &other) const
{
    const Fiction &otherFiction = static_cast<const Fiction &>(other);
    if (authorName == otherFiction.authorName)
    {
        return title < otherFiction.title;
    }
    else
    {
        return authorName < otherFiction.authorName;
    }
}

bool Fiction::operator>(const Item &other) const
{
    const Fiction &otherFiction = static_cast<const Fiction &>(other);
    if (authorName == otherFiction.authorName)
    {
        return title > otherFiction.title;
    }
    else
    {
        return authorName > otherFiction.authorName;
    }
}

bool Fiction::operator>=(const Item &other) const
{
    return (*this == other || *this > other);
}

bool Fiction::operator<=(const Item &other) const
{
    return (*this == other || *this < other);
}