// A Checkout allows a patron to borrow an item
// Drew Higginbotham

#include "checkout.h"
#include "itemfactory.h"
 
//----------------------------------------------------------------------------
// create
// allows action factory to create action pointer to checkOut object
Action *CheckOut::create() const
{
    return new CheckOut();
}

//----------------------------------------------------------------------------
// setData
// reads in data from data4commands.txt and assigns data members accordingly
// error checks, returning false if invalid data
bool CheckOut::setData(ifstream &inputFile, ItemFactory *itemFac)
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
// checks out a given item for a given user
// Retrieves the patron and item being acted on from item and user container
// Performs action on patron and item, and logs patron's history of commands
bool CheckOut::execute(Library *library)
{
    // uses currentID to assign patron item to matching patron found in h-table
    Patron *retrievedPatron = library->retrieveUser(currentID);
    // uses currentItem to assign item to matching book found in item bin tree
    currentItem = library->retrieveItem(tempItem);
    delete tempItem;
    tempItem = nullptr;
    // if item and patron exist in respective containers
    if (retrievedPatron == nullptr || currentItem == nullptr)
    {
        return false;
    }
    if (!currentItem->checkOut()) // checks if item available, updates count
    {
        return false;
    }
    retrievedPatron->checkOutItem(currentItem); // adds item to patron's books
    retrievedPatron->updateHistory(this);       // adds checkout to history
    return true;
}

//----------------------------------------------------------------------------
// display
// displays the type of action it is, along with the item that was acted on
void CheckOut::displayCommandType() const
{
    cout << "Checkout  ";
    currentItem->individualPrint();
}
