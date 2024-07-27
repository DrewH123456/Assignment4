// History prints out given patron's transaction history
// Drew Higginbotham

#ifndef HISTORY_H
#define HISTORY_H
#include "patron.h"
#include "book.h"
#include "library.h"
#include "action.h"

/*
 * History: The History class is a child class of Action and is executed by
 * the library, printing out given patron's transaction history
 * Overrides all pure virtual functions from Action, such as create, setData,
 * execute, and display
 *
 * Implementation and Assumptions:
 *   --setData reads in the id and always returns true, allowing
 *   readActions from library to continue executing the action
 *   --execute always returns false so readData can delete the display object
 *   --displayCommandType function not actually used in program 
 */

class ItemFactory;

class History : public Action
{
protected:
    int currentID; // tracks id of patron whose history is being displayed

public:
    // Constructor
    History(){};

    // Destructor
    virtual ~History(){};

    // allows actionFactory to create Action pointer to History object
    virtual Action *create() const;

    // reads id and returns true, allowing execute to be called in library's
    // readActions
    virtual bool setData(ifstream &inputFile, ItemFactory *itemFac);

    // takes given user and displays their history if existing patron.
    // displays "Patron has no history of transactions" if no history
    virtual bool execute(Library *library);

    // displays the type of action it is, "History"
    virtual void displayCommandType() const;
};

#endif
