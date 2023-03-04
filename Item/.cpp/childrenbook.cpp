/*
 * The ChildrenBook class represents a children book item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to children books, such as author and title
 */

#include "childrenbook.h"
#include "book.h"
#include "item.h"
#include <string>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------
// ChildrenBook
// Constructor
ChildrenBook::ChildrenBook()
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
void ChildrenBook::returnItem()
{
    available++;
    checkedOut--;
}

//---------------------------------------------------------------------------
// create
// Allows item factory to create a children book object
Item *ChildrenBook::create() const
{
    return new ChildrenBook();
}

//---------------------------------------------------------------------------
// setData
// sets item's data using info from line in infile
void ChildrenBook::setData(ifstream &inputFile)
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

void ChildrenBook::print(ostream &out) const
{
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