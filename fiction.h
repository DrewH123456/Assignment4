// A Fiction is a book that the library can lend
// Drew Higginbotham

#ifndef FICTION_H
#define FICTION_H
#include "book.h"
#include <string>
#include <iostream>
#include <fstream>

/*
 * Fiction: The Fiction class is a child class of Item and Book
 * Overrides all pure virtual functions from Book, such as checkOut, returnItem,
 * setData, and print
 *
 * Implementation and Assumptions:
 *   --has data members available and itemType derived from Book
 *   --has unique setData functions and print functions that are used
 *   differently throughout program. For example, setData and setDataCommand
 *   both exist, allowing data to be read in from data4books or data4commands
 */

class Fiction : public Book
{
protected:
    string authorName; // name of author
    string title;      // title of book
    int year;          // year published

public:
    // Constructor
    Fiction();

    // Destructor
    virtual ~Fiction();

    // Counts available copies
    virtual int countAvailable() const;

    // Returns item type for given item: 'F'
    virtual char returnItemType() const;

    // Checks out this book for a given user in a given library, first checking
    // if available, then updating count, otherwise printing error message
    virtual bool checkOut();

    // Returns this book for a given user in a given library
    virtual void returnItem();

    // Allows item factory to create an Item pointer to a fiction object
    virtual Item *create() const;

    // sets item's data using info from line in infile from data4books.txt
    virtual void setData(ifstream &inputFile);

    // sets item's data using info from line in infile from data4commands.txt
    virtual void setDataCommand(ifstream &inputFile);

    // prints book's description: available, author, title, year
    virtual void print(ostream &out) const;

    // prints individual book's description: title, author, year
    virtual void individualPrint() const;

    // prints heading for individual book description: title, author, year
    virtual void printHeading() const;

    // Overloaded comparison operators, comparing author, then title
    virtual bool operator<(const Item &other) const;
    virtual bool operator>(const Item &other) const;
    virtual bool operator>=(const Item &other) const;
    virtual bool operator<=(const Item &other) const;
    virtual bool operator==(const Item &other) const;
    virtual bool operator!=(const Item &other) const;
};
#endif