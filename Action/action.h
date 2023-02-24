/*
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
protected:
    Patron *p; // Pointer to the patron for the action
    Item *i;   // Pointer to the item for the action
    Library *l // Pointer to library for the action

        public :
        // Pure virtual default constructor
        virtual Action() = 0;

    // Virtual destructor
    virtual ~Action();

    // sets private variables based off info from text file
    Book *setItem();

    Patron *setPatron();

    Library *setLibrary();

    // executes the given action
    virtual bool execute() = 0;
};

#endif