/*
 * The Fiction class represents a periodical item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to periodicals, such as the date issues and title.
 */

#include "fiction.h" 
#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------
// Fiction
// Constructor
Fiction::Fiction()
{
    available = 5;
    itemType = 'F';
}

Fiction::~Fiction()
{
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int Fiction::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// returnItemType
// Returns item type for given item
char Fiction::returnItemType() const
{
    return itemType;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
bool Fiction::checkOut()
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
void Fiction::returnItem()
{
    available++;
}

//---------------------------------------------------------------------------
// create
// Allows item factory to create a fiction object
Item *Fiction::create() const
{
    return new Fiction();
}

//---------------------------------------------------------------------------
// setData
// sets item's data using info from line in infile from data4bookss.txt
void Fiction::setData(ifstream &inputFile)
{
    inputFile.get();
    getline(inputFile, authorName, ',');
    inputFile.get();
    getline(inputFile, title, ',');
    inputFile >> year;
}

//---------------------------------------------------------------------------
// setDataCommand
// sets item's data using info from line in infile from data4commands.txt
void Fiction::setDataCommand(ifstream &inputFile)
{
    inputFile.get();
    getline(inputFile, authorName, ',');
    inputFile.get();
    getline(inputFile, title, ',');
}

//---------------------------------------------------------------------------
// print
// prints book's description
void Fiction::print(ostream &out) const
{
    const Fiction &fiction = static_cast<const Fiction &>(*this);
    cout << "  " << setw(8) << left << fiction.available
         << setw(25) << left << fiction.authorName
         << setw(35) << left << fiction.title
         << setw(10) << right << fiction.year << endl;
}

//---------------------------------------------------------------------------
// individualPrint
// prints individual book's description
void Fiction::individualPrint() const
{
    const Fiction &fiction = static_cast<const Fiction &>(*this);
    cout << left << setw(30) << title << "   " << setw(20) << left << authorName
         << setw(5) << right << year << endl;
    cout << endl;
}

void Fiction::printHeading() const
{
    cout << "Fiction:" << endl;
    cout << setw(12) << left << "AVAIL"
         << setw(25) << left << "AUTHOR"
         << setw(35) << left << "TITLE"
         << setw(8) << right << "YEAR" << endl;
}

//---------------------------------------------------------------------------
// operator
// Overloaded comparison operators
bool Fiction::operator==(const Item &other) const
{
    const Fiction &otherFiction = static_cast<const Fiction &>(other);
    return (authorName == otherFiction.authorName &&
            title == otherFiction.title);
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
