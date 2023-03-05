/*
 * This is a child class of action, overriding the execute function to display
 * the history of a user's transactions
 */

#ifndef HISTORY_H
#define HISTORY_H

#include "patron.h"
#include "book.h"
#include "library.h"
#include "action.h"

class History : public Action
{
private:
public:
    // Constructor
    History();

    // Destructor
    virtual ~History();

    // creates an action pointer to an object of the history class
    virtual Action *create() const;

    // displays a given user's transaction history
    virtual bool execute();
};

#endif