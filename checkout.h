// A Checkout allows a patron to borrow an item
// Drew Higginbotham

#ifndef CHECKOUT_H
#define CHECKOUT_H
#include "action.h"
 
/*
 * Checkout: The Checkout class is a child class of Action and
 * is executed by the library, allowing a given patron to borrow an item.
 * Overrides all pure virtual functions from Action, such as create, setData,
 * execute, and display
 *
 * Implementation and Assumptions:
 *   --contains members: currentID, tempItem, currentItem, which
 *   allow execute to perform actions on desired item or patrons
 *   --validates that item is able to be checked out or that patrons or item
 *   exist in library
 */

class Library;
class ItemFactory;

class CheckOut : public Action
{
protected:
    int currentID;               // id number of patron being acted on
    Item *tempItem;              // temp item storing partial info
    Item *currentItem = nullptr; // item retrieved from library's bintree

public:
    // constructor
    CheckOut(){};

    // virtual destructor
    virtual ~CheckOut(){};

    // allows actionFactory to create action pointer to checkOut object
    virtual Action *create() const;

    // reads in data from data4commands.txt and assigns data members accordingly
    // error checks, returning false if invalid data
    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // checks out a given item for a given user
    // Retrieves the patron and item being acted on from item and user container
    // Performs action on patron and item, and logs patron's history of commands
    virtual bool execute(Library *library);

    // displays the type of action it is, along with the item that was acted on
    virtual void displayCommandType() const;
};

#endif
