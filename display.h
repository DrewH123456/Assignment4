/*
 * This is a child class of action, overriding the execute function to display
 * the contents
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "action.h"

class Library;
class ItemFactory;

class Display : public Action
{
public:
    // Constructor
    Display(){};

    // Destructor
    virtual ~Display(){};

    // creates an action pointer to an object of the checkOut class
    virtual Action *create() const;

    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // checks out a given book for a given user
    virtual bool execute(Library *library);

    // displays the type of action it is
    virtual void display() const;
};

#endif