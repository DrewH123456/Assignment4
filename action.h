// An Action is a parent class whose children are actions executed in library
// Drew Higginbotham

#ifndef ACTION_H
#define ACTION_H

#include "patron.h"
#include "book.h"
#include "library.h"

/*
 * Action: The Action class is an abstract class that stores a child action. 
 * Its children include checkout, return, display, and history. All of
 * its functions, such as execute, setData, create, and display are pure
 * virtual
 *
 * Implementation and Assumptions:
 *   --All functions must be implemented by children
 *   --Contains a virtual destructor
 */

class Action
{
public:
    // Default constructor
    Action(){};

    // Virtual destructor
    virtual ~Action(){};

    // Executes the given action
    virtual bool execute(Library *library) = 0;

    // Assigns the action's data members based on given text file
    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac) = 0;

    // creates and returns an action pointer to an object of the checkOut class
    virtual Action *create() const = 0;

    // Displays the given action and its stored data members
    virtual void displayCommandType() const = 0;
};

#endif
