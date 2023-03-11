/*
 * The ChildrenBook class represents a children book item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to children books, such as author and title
 */

#include "childrenbook.h"
#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------
// ChildrenBook
// Constructor
ChildrenBook::ChildrenBook()
{
    available = 5;
    itemType = 'C';
}

ChildrenBook::~ChildrenBook()
{
}

//---------------------------------------------------------------------------
// countAvailable
// Counts available copies
int ChildrenBook::countAvailable() const
{
    return available;
}

//---------------------------------------------------------------------------
// returnItemType
// Returns item type for given item
char ChildrenBook::returnItemType() const
{
    return itemType;
}

//---------------------------------------------------------------------------
// checkOut
// Checks out this book for a given user in a given library
bool ChildrenBook::checkOut()
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
void ChildrenBook::returnItem()
{
    available++;
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
    inputFile.get();
    getline(inputFile, authorName, ',');
    inputFile.get();
    getline(inputFile, title, ',');
    inputFile >> year;
}

//---------------------------------------------------------------------------
// setData
// sets item's data using info from line in infile from data4commands.txt
void ChildrenBook::setDataCommand(ifstream &inputFile)
{
    inputFile.get();
    getline(inputFile, title, ',');
    inputFile.get();
    getline(inputFile, authorName, ',');
}

void ChildrenBook::print(ostream &out) const
{
    const ChildrenBook &children = static_cast<const ChildrenBook &>(*this);
    out << setw(5) << children.available << setw(15) << children.authorName
        << setw(15) << children.title
        << setw(10) << children.year << endl;
}

//---------------------------------------------------------------------------
// individualPrint
// prints individual book's description
void ChildrenBook::individualPrint() const
{
    const ChildrenBook &childrenBook = static_cast<const ChildrenBook &>(*this);
    cout << setw(28) << "    " << childrenBook.title
         << setw(15) << "    " << childrenBook.authorName
         << setw(4) << childrenBook.year << endl;
}

//---------------------------------------------------------------------------
// operator
// Overloaded comparison operators
bool ChildrenBook::operator==(const Item &other) const
{
    const ChildrenBook &otherChildrenBook =
        static_cast<const ChildrenBook &>(other);
    return (authorName == otherChildrenBook.authorName &&
            title == otherChildrenBook.title);
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
