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

void CheckOut::setData(ifstream &inputFile, ItemFactory *itemFac)
{
    string dummy;   // used in final getLine to move inputFile to next line
    char itemType;  // takes in item type
    char coverType; // takes in cover type

    currentPatron->setDataCommand(inputFile); // assigns id to currentPatron
    inputFile >> itemType;
    currentItem = itemFac->createIt(itemType); // creates item using factory
    inputFile >> coverType;
    if (coverType != 'H') // validates book cover type
    {
        cout << "Invalid cover type" << endl;
        delete currentItem;
        currentItem = nullptr;
        getline(inputFile, dummy, '\n');
        return;
    }
    currentItem->setDataCommand(inputFile); // sets item's data
    getline(inputFile, dummy, '\n');        // skips to next line
}

bool CheckOut::execute()
{
}