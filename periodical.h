// A Periodical is a book that the library can lend
// Drew Higginbotham

#ifndef PERIODICAL_H
#define PERIODICAL_H
#include "book.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Periodical: The Periodical class is a child class of Item and Book
 * Overrides all pure virtual functions from Book, such as checkOut, returnItem,
 * setData, and print
 *
 * Implementation and Assumptions:
 *   --has data members available and itemType derived from Book
 *   --has unique setData functions and print functions that are used
 *   differently throughout program. For example, setData and setDataCommand
 *   both exist, allowing data to be read in from data4books or data4commands
 */

class Periodical : public Book
{
protected:
    int year;     // year published
    int month;    // month published
    string title; // title of book

public:
    // Constructor
    Periodical();

    // Destructor
    virtual ~Periodical();

    // Counts available copies
    virtual int countAvailable() const;

    // Returns item type for given item: 'P'
    virtual char returnItemType() const;

    // Checks out this book for a given user in a given library, first checking
    // if available, then updating count, otherwise printing error message
    virtual bool checkOut();

    // Returns this book for a given user in a given library
    virtual void returnItem();

    // Allows item factory to create an Item pointer to a periodical object
    virtual Item *create() const;

    // sets item's data using info from line in infile from data4books.txt
    virtual void setData(ifstream &inputFile);

    // sets item's data using info from line in infile from data4commands.txt
    virtual void setDataCommand(ifstream &inputFile);

    // prints book's description: available, month, year, title
    virtual void print(ostream &out) const;

    // prints individual book's description: month, year, title
    virtual void individualPrint() const;

    // prints heading for individual book description: month, year, title
    virtual void printHeading() const;

    // Overloaded comparison operators, comparing year, then month, then title
    virtual bool operator<(const Item &other) const;
    virtual bool operator>(const Item &other) const;
    virtual bool operator>=(const Item &other) const;
    virtual bool operator<=(const Item &other) const;
    virtual bool operator==(const Item &other) const;
    virtual bool operator!=(const Item &other) const;
};

#endif