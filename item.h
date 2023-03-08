/**
 * The Item class represents a collection of a given item in the library system.
 * It contains information about the number of checked out/available items
 * The Item class serves as the parent class for Book.
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Item
{
protected:
    int available;  // available item count
    int checkedOut; // checked out item count

public:
    Item(){};

    // Destructor
    virtual ~Item(){};

    // Checks available count for given item
    virtual int countAvailable() const = 0;

    // Checks checked out count for given item
    virtual int countCheckedOut() const = 0;

    // Checks out this item for a given user
    virtual void checkOut() = 0;

    // Returns this item for a given user
    virtual void returnItem() = 0;

    // Allows item factory to create an item
    virtual Item *create() const = 0;

    virtual void setData(ifstream &inputFile) = 0;

    virtual void setDataCommand(ifstream &inputFile) = 0;

    virtual void print(ostream &out) const = 0;

    // Overloaded output operator
    // virtual ostream &operator<<(ostream &output, const Item &item) const = 0;

    // Overloaded comparison operators
    virtual bool operator<(const Item &other) const = 0;
    virtual bool operator>(const Item &other) const = 0;
    virtual bool operator>=(const Item &other) const = 0;
    virtual bool operator<=(const Item &other) const = 0;
    virtual bool operator==(const Item &other) const = 0;
    virtual bool operator!=(const Item &other) const = 0;
};

#endif