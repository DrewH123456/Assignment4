/**
 * The Item class represents a collection of a given item in the library system.
 * It contains information about the number of checked out/available items
 * The Item class serves as the parent class for Book.
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "patron.h"
using namespace std;

class Item
{
protected:
    vector<Patron *> users;
    int available;
    int checkedOut;

public:
    // constructor, setting corresponding data members
    Item();

    // Destructor
    virtual ~Item();

    // Checks available count for given item
    virtual int countAvailable() const = 0;

    // Checks checked out count for given item
    virtual int countCheckedOut() const = 0;

    // Checks out this item for a given user
    virtual void checkOut() = 0;

    // Returns this item for a given user
    virtual void returnItem() = 0;

    // Overloaded comparison operators
    // pointer or object???
    virtual bool operator<(const Item &other) const = 0;
    virtual bool operator>(const Item &other) const = 0;
    virtual bool operator>=(const Item &other) const = 0;
    virtual bool operator>=(const Item &other) const = 0;
    virtual bool operator==(const Item &other) const = 0;
    virtual bool operator!=(const Item &other) const = 0;
};

#endif