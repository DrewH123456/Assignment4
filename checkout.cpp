/*
 * This is a child class of action, overriding the execute function to check
 * out a book for a user
 */

#include "checkout.h"
#include "itemfactory.h"

Action *CheckOut::create() const
{
    return new CheckOut();
}

bool CheckOut::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    string dummy;   // used in final getLine to move inputFile to next line
    char itemType;  // takes in item type
    char coverType; // takes in cover type

    inputFile >> currentID;
    if (currentID < 0 || currentID > 9999) // checks if id is valid
    {
        getline(inputFile, dummy, '\n');
        return false;
    }
    inputFile >> itemType;
    inputFile >> coverType;
    if (coverType != 'H') // validates book cover type
    {
        cout << "Invalid cover type" << endl;
        getline(inputFile, dummy, '\n');
        return false;
    }
    currentItem = itemFac->createIt(itemType);
    if (currentItem == nullptr) // if invalid book type, return false
    {
        getline(inputFile, dummy, '\n');
        return false;
    }
    currentItem->setDataCommand(inputFile); // sets item's data
    getline(inputFile, dummy, '\n');        // skips to next line
    return true;
}

bool CheckOut::execute(Library *library) // delete command if no success
{
    // uses currentID to assign patron item to matching patron found in h-table
    Patron *retrievedPatron = library->retrieveUser(currentID);
    // uses currentItem to assign item to matching book found in item bin tree
    retrievedItem = library->retrieveItem(currentItem);
    if (retrievedPatron == nullptr || retrievedItem == nullptr)
    {
        return false;
    }
    retrievedItem->print(cout);
    if (!retrievedItem->checkOut()) // checks if item available, updates count
    {
        return false;
    }
    retrievedPatron->checkOutItem(retrievedItem); // adds item to patron's books
    retrievedPatron->updateHistory(this);         // adds checkout to history
    return true;
}

void CheckOut::display() const
{

    cout << "Checkout  ";
}