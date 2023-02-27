/*
 * The Periodical class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the year, month, and title.
 */

#include "periodical.h"
#include "book.h"
#include "item.h"
#include <string>
using namespace std;

//---------------------------------------------------------------------------
// Periodical
// Constructor
Periodical::Periodical()
    : Book()
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// Periodical
// Constructor, setting corresponding data members
Periodical::Periodical(string title, int month, int year)
    : Book(), title(title), month(month), year(year)
{
    available = 5;
    checkedOut = 0;
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int Periodical::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// countCheckedOut
// Counts checked out count for given book
int Periodical::countCheckedOut() const
{
    return checkedOut;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
void Periodical::checkOut()
{
    available--;
    checkedOut++;
}

//---------------------------------------------------------------------------
// returnBook
// Returns this book for a given user in a given library
void Periodical::returnBook()
{
    available++;
    checkedOut--;
}

//---------------------------------------------------------------------------
// operator
// Overloaded comparison operators
bool Periodical::operator==(const Item &other) const
{
    const Periodical &otherPeriodical =
        static_cast<const Periodical &>(other);
    return (year == otherPeriodical.year &&
            month == otherPeriodical.month && title == otherPeriodical.title);
}

bool Periodical::operator!=(const Item &other) const
{
    return !(*this == other);
}

bool Periodical::operator<(const Item &other) const
{
    const Periodical &otherPeriodical =
        static_cast<const Periodical &>(other);
    if (year == otherPeriodical.year && month == otherPeriodical.month)
    {
        return (title < otherPeriodical.title);
    }
    else if (year == otherPeriodical.year)
    {
        return (month < otherPeriodical.month);
    }
    else
    {
        return (year < otherPeriodical.year);
    }
}

bool Periodical::operator>(const Item &other) const
{
    const Periodical &otherPeriodical =
        static_cast<const Periodical &>(other);
    if (year == otherPeriodical.year && month == otherPeriodical.month)
    {
        return (title > otherPeriodical.title);
    }
    else if (year == otherPeriodical.year)
    {
        return (month > otherPeriodical.month);
    }
    else
    {
        return (year > otherPeriodical.year);
    }
}

bool Periodical::operator>=(const Item &other) const
{
    return (*this == other || *this > other);
}

bool Periodical::operator<=(const Item &other) const
{
    return (*this == other || *this < other);
}