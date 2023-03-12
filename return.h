// A Return allows a patron to return an item
// Drew Higginbotham

#ifndef RETURN_H
#define RETURN_H
#include "patron.h"
#include "book.h"
#include "library.h"
#include "action.h"

/*
 * Checkout: The Return class is a child class of Action and
 * is executed by the library, allowing a given patron to return an item.
 * Overrides all pure virtual functions from Action, such as create, setData,
 * execute, and display
 *
 * Implementation and Assumptions:
 *   --contains members: currentID, tempItem, currentItem, which
 *   allow execute to perform actions on desired item or patrons
 *   --validates that item is able to be returned or that patrons or item
 *   exist in library
 */

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

    // virtual destructor
    virtual ~Return(){};

    // allows actionFactory to create action pointer to Return object
    virtual Action *create() const;

    // reads in data from data4commands.txt and assigns data members accordingly
    // error checks, returning false if invalid data
    bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // returns a given item from a given user
    // Retrieves the patron and item being acted on from item and user container
    // Performs action on patron and item, and logs patron's history of commands
    virtual bool execute(Library *library);

    // displays the type of action it is, along with the item that was acted on
    virtual void displayCommandType() const;
};

#endif