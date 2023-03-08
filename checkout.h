/*
 * This is a child class of action, overriding the execute function to check
 * out a book for a user
 */

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "patron.h"
#include "book.h"
#include "library.h"
#include "action.h"

class ItemFactory;

class CheckOut : public Action
{
protected:
    Patron *currentPatron; // Pointer to the patron for the action
    Item *currentItem;     // Pointer to the item for the action
public:
    // Constructor
    CheckOut(){};

    // Destructor
    virtual ~CheckOut(){};

    // creates an action pointer to an object of the checkOut class
    virtual Action *create() const;

    virtual void setData(ifstream &inputFile, ItemFactory *itemFac);

    // checks out a given book for a given user
    virtual bool execute();
};

#endif