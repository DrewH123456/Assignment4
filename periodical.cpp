/*
 * The Periodical class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the year, month, and title.
 */

#include "periodical.h"
#include <iomanip>

//---------------------------------------------------------------------------
// Periodical
// Constructor
Periodical::Periodical()
{
    available = 1;
    itemType = 'P';
}

Periodical::~Periodical()
{
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int Periodical::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// returnItemType
// Returns item type for given item
char Periodical::returnItemType() const
{
    return itemType;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
bool Periodical::checkOut()
{
    if (available > 0)
    {
        available--;
        return true;
    }
    cout << "Book unavailable at this time" << endl;
    return false;
}

//---------------------------------------------------------------------------
// returnBook
// Returns this book for a given user in a given library
void Periodical::returnItem()
{
    available++;
}

//---------------------------------------------------------------------------
// create
// Allows item factory to create a periodical object
Item *Periodical::create() const
{
    return new Periodical();
}

//---------------------------------------------------------------------------
// setData
// sets item's data using info from line in infile
void Periodical::setData(ifstream &inputFile)
{
    string dummy; // used in final getLine to move inputFile to next line

    inputFile.get();
    getline(inputFile, title, ',');
    inputFile >> month;
    inputFile >> year;
    getline(inputFile, dummy, '\n');
}

//---------------------------------------------------------------------------
// setDataCommand
// sets item's data using info from line in infile from data4commands.txt
void Periodical::setDataCommand(ifstream &inputFile)
{
    inputFile >> year;
    inputFile >> month;
    inputFile.get();
    getline(inputFile, title, ',');
}

//---------------------------------------------------------------------------
// print
// prints book's description
void Periodical::print(ostream &out) const
{
    const Periodical &periodical = static_cast<const Periodical &>(*this);
    out << setw(5) << periodical.available << setw(15) << "" << setw(25)
        << periodical.title << setw(5) << periodical.month << setw(5) << periodical.year << endl;
}

//---------------------------------------------------------------------------
// individualPrint
// prints individual book's description
void Periodical::individualPrint() const
{
    const Periodical &periodical = static_cast<const Periodical &>(*this);
    cout << setw(3) << periodical.month << setw(6) << periodical.year << setw(70) << periodical.title << endl;
}

//---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
// virtual ostream &operator<<(ostream &output, const Item &item) const
// {
// }

//---------------------------------------------------------------------------
// operators
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