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

class Return : public Action
{
private:
public:
    // Constructor
    Return();

    // Destructor
    virtual ~Return();

    // creates an action pointer to an object of the return class
    virtual Action *create() const;

    // returns a given book for a given user
    virtual bool execute();
};

#endif