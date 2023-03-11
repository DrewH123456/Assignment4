// An Action is a parent class whose children are actions the library executes
// Drew Higginbotham

#ifndef ACTION_H
#define ACTION_H

#include "patron.h"
#include "book.h"
#include "library.h"

/*
 * Action: The Action class is an abstract class that the library must perform.
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

    // Creates an instance of this specific action and returns it
    virtual Action *create() const = 0;

    // Displays the given action and its stored data members
    virtual void display() const = 0;
};

#endif