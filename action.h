/**
 * The Action class is the action that should be taken by the library
 * This class is an abstract class, served as the parent class for factory
 */

#ifndef ACTION_H
#define ACTION_H

#include "patron.h"
#include "book.h"
#include "library.h"

class Action
{
public:
    // Pure virtual default constructor
    Action(){};

    // Virtual destructor
    virtual ~Action(){};

    // executes the given action
    virtual bool execute(Library *library) = 0;

    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac) = 0;

    virtual Action *create() const = 0;

    // displays the type of action it is
    virtual void display() const = 0;
};

#endif