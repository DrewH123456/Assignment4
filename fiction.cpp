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
// setData
// sets item's data using info from line in infile
void Fiction::setData(ifstream &inputFile)
{
    string author;
    string title;
    int year;
    string dummy; // used in final getLine to move inputFile to next line

    inputFile.get();
    getline(inputFile, author, ',');
    inputFile.get();
    getline(inputFile, title, ',');
    inputFile >> year;
    getline(inputFile, dummy, '\n');
}

//---------------------------------------------------------------------------
// print
// prints book's description
void Fiction::print(ostream &out) const
{
    out << setw(5) << available << setw(15) << authorName << setw(15) << title
        << setw(10) << year << endl;
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