/*
 * This is a child class of action, overriding the execute function to display
 * the history of a user's transactions
 */

#include "history.h"
#include "itemfactory.h"

Action *History::create() const
{
    return new History();
}

bool History::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    inputFile >> currentID;
    return true;
}

bool History::execute(Library *library) // delete command if no success
{
    Patron *retrievedPatron = library->retrieveUser(currentID);
    if (retrievedPatron != nullptr)
    {
        retrievedPatron->viewHistory();
    }
    return false;
}

void History::display() const
{
    cout << "History  ";
}