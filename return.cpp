// A Return allows a patron to return an item
// Drew Higginbotham

#include "return.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// create
// allows actionFactory to create action pointer to Return object
Action *Return::create() const
{
    return new Return();
}

//----------------------------------------------------------------------------
// setData
// reads in data from data4commands.txt and assigns data members accordingly
// error checks, returning false if invalid data
bool Return::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    char itemType;  // takes in item type
    char coverType; // takes in cover type

    inputFile >> currentID;
    if (currentID < 0 || currentID > 9999) // checks if id is valid
    {
        return false;
    }
    inputFile >> itemType;
    inputFile >> coverType;
    if (coverType != 'H') // validates book cover type
    {
        cout << "Invalid cover type" << endl;
        return false;
    }
    tempItem = itemFac->createIt(itemType);
    if (tempItem == nullptr) // if invalid book type, return false
    {
        return false;
    }
    tempItem->setDataCommand(inputFile); // sets item's data

    return true;
}

//----------------------------------------------------------------------------
// execute
// returns a given item from a given user
// Retrieves the patron and item being acted on from item and user container
// Performs action on patron and item, and logs patron's history of commands
bool Return::execute(Library *library) // delete command if no success
{
    // uses currentID to assign patron item to matching patron found in h-table
    Patron *retrievedPatron = library->retrieveUser(currentID);
    // uses currentItem to assign item to matching book found in item bin tree
    currentItem = library->retrieveItem(tempItem);
    delete tempItem;
    tempItem = nullptr;
    // if patron or item not found
    if (retrievedPatron == nullptr || currentItem == nullptr)
    {
        return false;
    }
    // if patron does not own the item
    if (!retrievedPatron->returnItem(currentItem))
    {
        cout << "Item not found in patron's borrowed items collection" << endl;
        return false;
    }
    currentItem->returnItem();            // increments items inventory
    retrievedPatron->updateHistory(this); // adds checkout to history
    return true;
}

// displays the type of action it is, along with the item that was acted on
// displayCommandType
void Return::displayCommandType() const
{
    cout << "Return    ";
    currentItem->individualPrint();
}