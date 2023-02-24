/*
 * This is a factory for class Action
 * The factory will produce different children objects of action for the library
 * to create, allowing the action to be executed when the action is processed
 */

#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include "action.h"
#include "checkout.h"
#include "return.h"
#include "history.h"

class ActionFactory
{
private:
    Action *objFactory[10];  // contains array of each object
    int hash(char ch) const; // hash function

public:
    // Factory constructor, initializes objFactory
    ActionFactory();

    // Factory destructor, deletes objFactory
    ~ActionFactory();

    // Creates a corresponding action based on the information provided
    Action *createIt(char c) const;
};

#endif