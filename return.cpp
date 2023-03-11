/*
 * This is a child class of action, overriding the execute function to return
 * a book for a user
 */

#include "return.h"
#include "itemfactory.h"

Action *Return::create() const
{
    return new Return();
}

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

bool Return::execute(Library *library) // delete command if no success
{
    // uses currentID to assign patron item to matching patron found in h-table
    Patron *retrievedPatron = library->retrieveUser(currentID);
    // uses currentItem to assign item to matching book found in item bin tree
    currentItem = library->retrieveItem(tempItem);
    delete tempItem;
    tempItem = nullptr;
    if (retrievedPatron == nullptr || currentItem == nullptr)
    {
        return false;
    }
    if (!retrievedPatron->returnItem(currentItem))
    {
        cout << "Item not found in patron's borrowed items collection" << endl;
        return false;
    }
    currentItem->returnItem();            // increments items inventory
    retrievedPatron->updateHistory(this); // adds checkout to history
    cout << "execute worked" << endl;
    return true;
}

void Return::display() const
{
    cout << "Return    ";
    currentItem->individualPrint();
}