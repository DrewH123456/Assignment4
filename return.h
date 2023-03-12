/*
 * This is a child class of action, overriding the execute function to return
 * a book for a user
 */

#ifndef RETURN_H
#define RETURN_H

#include "patron.h"
#include "book.h"
#include "library.h"
#include "action.h"

class ItemFactory;

class Return : public Action
{
protected:
    int currentID;               // id number of patron being acted on
    Item *tempItem;              // item containing data of item being acted on
    Item *currentItem = nullptr; // item retrieved from library's bintree

public:
    // Constructor
    Return(){};

    // Destructor
    virtual ~Return(){};

    // creates and returns an action pointer to an object of the checkOut class
    fdauofjdoi virtual Action *create() const;

    bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // returns a given item from a given user
    // Retrieves the patron and item being acted on from item and user container
    // Performs action on patron and item, and logs patron's history of commands
    virtual bool execute(Library *library);

    // displays the type of action it is
    virtual void display() const;
};

#endif