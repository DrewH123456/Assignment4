// A Periodical is a book that the library can lend
// Drew Higginbotham

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

//---------------------------------------------------------------------------
// ~Periodical
// Destructor
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
// Returns item type for given item, 'P'
char Periodical::returnItemType() const
{
    return itemType;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library, first checking
// if available, then updating count, otherwise printing error message
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
// Allows item factory to create an Item pointer to a periodical object
Item *Periodical::create() const
{
    return new Periodical();
}

//---------------------------------------------------------------------------
// setData
// sets item's data using info from line in infile from data4books.txt
void Periodical::setData(ifstream &inputFile)
{
    inputFile.get();
    getline(inputFile, title, ',');
    inputFile >> month;
    inputFile >> year;
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
// prints book's description: available, month, year, title
void Periodical::print(ostream &out) const
{
    const Periodical &periodical = static_cast<const Periodical &>(*this);
    cout << "  " << setw(8) << left << periodical.available << " "
         << setw(12) << periodical.month
         << setw(12) << periodical.year
         << setw(40) << periodical.title << endl;
}

//---------------------------------------------------------------------------
// individualPrint
// prints individual book's description: month, year, title
void Periodical::individualPrint() const
{
    const Periodical &periodical = static_cast<const Periodical &>(*this);
    cout << setw(5) << left << periodical.month << setw(8)
         << left << periodical.year << setw(40)
         << left << periodical.title << endl;
    cout << endl;
}

// printHeading
// prints heading for individual book description: month, year, title
void Periodical::printHeading() const
{
    cout << "Periodical:" << endl;
    cout << setw(9) << left << "AVAIL"
         << setw(14) << left << "MONTH"
         << setw(14) << left << "YEAR"
         << setw(33) << left << "TITLE" << endl;
}

//---------------------------------------------------------------------------
// operators
// Overloaded comparison operators, comparing year, then month, then title
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