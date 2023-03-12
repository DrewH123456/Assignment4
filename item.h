// A Book is a parent class whose children are items the library lends
// Drew Higginbotham

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Item: The Item class is an abstract class whose children include Book.
 * It has minimal implementation, besides data members: available and itemType
 *
 * Implementation and Assumptions:
 *   --All functions must be implemented by children
 *   --Contains a virtual destructor
 */

class Item
{
protected:
    int available; // available item count
    char itemType; // item type, represented by char

public:
    // Constructor
    Item(){};

    // Destructor
    virtual ~Item(){};

    // Checks available count for given item
    virtual int countAvailable() const = 0;

    // Returns item type for given item
    virtual char returnItemType() const = 0;

    // Checks out this item for a given user
    virtual bool checkOut() = 0;

    // Returns this item for a given user
    virtual void returnItem() = 0;

    // Allows item factory to create an item
    virtual Item *create() const = 0;

    virtual void setData(ifstream &inputFile) = 0;

    virtual void setDataCommand(ifstream &inputFile) = 0;

    virtual void print(ostream &out) const = 0;

    virtual void individualPrint() const = 0;

    virtual void printHeading() const = 0;

    // Overloaded comparison operators
    virtual bool operator<(const Item &other) const = 0;
    virtual bool operator>(const Item &other) const = 0;
    virtual bool operator>=(const Item &other) const = 0;
    virtual bool operator<=(const Item &other) const = 0;
    virtual bool operator==(const Item &other) const = 0;
    virtual bool operator!=(const Item &other) const = 0;
};

#endif