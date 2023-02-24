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

class CheckOut : public Action
{
private:
public:
    // Constructor
    CheckOut();

    // Destructor
    virtual ~CheckOut();

    // creates an action pointer to an object of the checkOut class
    virtual Action *create() const;

    // checks out a given book for a given user
    virtual bool execute();
};

#endif