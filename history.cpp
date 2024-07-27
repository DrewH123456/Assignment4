// History prints out given patron's transaction history
// Drew Higginbotham

#include "history.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// create
// allows actionFactory to create Action pointer to History object 
Action *History::create() const
{
    return new History();
}

//----------------------------------------------------------------------------
// setData
// reads id and returns true, allowing execute to be called in library's
// readActions
bool History::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    inputFile >> currentID;
    return true;
}

//----------------------------------------------------------------------------
// execute
// takes given user and displays their history if existing patron.
// displays "Patron has no history of transactions" if no history
bool History::execute(Library *library)
{
    Patron *retrievedPatron = library->retrieveUser(currentID);
    if (retrievedPatron == nullptr) // if patron doesn't exist
    {
        cout << "Patron with id: " << currentID << " does not exist" << endl;
    }
    if (retrievedPatron != nullptr) // if patron exists
    {
        retrievedPatron->viewHistory(); // ADD IDDDD
    }
    return false;
}

//----------------------------------------------------------------------------
// displays the type of action it is, "History"
void History::displayCommandType() const
{
    cout << "History  ";
}
