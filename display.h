// Display prints out all of the items in the library in sorted order
// Drew Higginbotham

#ifndef DISPLAY_H
#define DISPLAY_H
#include "action.h"

/*
 * Display: The Display class is a child class of Action and is executed by
 * the library, displaying all of the categories of items from itemContainer,
 * where each category displays its items in sorted order.
 * Overrides all pure virtual functions from Action, such as create, setData,
 * execute, and display
 *
 * Implementation and Assumptions:
 *   --setData has no implementation besides returning true, allowing
 *   readActions from library to continue executing the action
 *   --execute always returns false so readData can delete the display object
 *   --displayCommandType function not actually used in program
 */

class Library;
class ItemFactory;

class Display : public Action
{
public:
    // Constructor
    Display(){};

    // Destructor
    virtual ~Display(){};

    // allows actionFactory to create Action pointer to Display object
    virtual Action *create() const;

    // returns true, allowing execute to be called in library's readActions
    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // calls on library->displayItems, displaying each category of itemContainer
    // where each category's items are displayed in sorted order
    virtual bool execute(Library *library);

    // displays the type of action it is, "Display"
    virtual void displayCommandType() const;
};

#endif