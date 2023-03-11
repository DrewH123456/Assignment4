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
    int currentID;               // id number of patron being acted on
    Item *tempItem;              // temp item storing partial info
    Item *currentItem = nullptr; // item retrieved from library's bintree

public:
    // Constructor
    CheckOut(){};

    // Destructor
    virtual ~CheckOut(){};

    // creates an action pointer to an object of the checkOut class
    virtual Action *create() const;

    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // checks out a given book for a given user
    virtual bool execute(Library *library);

    // displays the type of action it is
    virtual void display() const;
};

#endif