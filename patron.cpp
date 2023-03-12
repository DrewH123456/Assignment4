// A Patron is a member of the library and can make transactions of items
// Drew Higginbotham

#include "patron.h"
#include "action.h"
#include "item.h"

//---------------------------------------------------------------------------
// ~Patron
// destructor, deletes patron's history of transactions
Patron::~Patron()
{
    for (int i = 0; i < history.size(); i++)
    {
        delete history[i];
        history[i] = nullptr;
    }
};

//---------------------------------------------------------------------------
// setData
// sets patron's data using info from line in infile from data4patrons.txt
void Patron::setData(ifstream &inputFile)
{
    inputFile >> idNumber;
    inputFile >> lastName;
    inputFile >> firstName;
    string dummy;
    getline(inputFile, dummy, '\n'); // skips to next line
}

//---------------------------------------------------------------------------
// setDataCommand
// sets patron's data using info from line in infile from data4commands.txt
void Patron::setDataCommand(ifstream &inputFile)
{
    inputFile >> idNumber;
}

//---------------------------------------------------------------------------
// getId
// Returns the unique identifier for the patron
int Patron::getId() const
{
    return idNumber;
}

//---------------------------------------------------------------------------
// getLastName
// Returns the last name of the patron
string Patron::getLastName() const
{
    return lastName;
}

//---------------------------------------------------------------------------
// getFirstName
// Returns the first name of the patron
string Patron::getFirstName() const
{
    return firstName;
}

//---------------------------------------------------------------------------
// print
// Displays patron's id and name
void Patron::print() const
{
    cout << idNumber << ": " << lastName << ", " << firstName << endl;
}

//---------------------------------------------------------------------------
// displayItems
// Display patron's borrowed items
void Patron::displayItems() const
{
    for (int i = 0; i < checkedOutItems.size(); i++)
    {
        checkedOutItems[i]->individualPrint();
    }
}

//---------------------------------------------------------------------------
// checkOutItem
// item added to patron's checkedOutItems collection
void Patron::checkOutItem(Item *addItem)
{
    checkedOutItems.push_back(addItem);
}

//---------------------------------------------------------------------------
// returnItem
// Removes an item from the list of items checked out by the patron
// returns false if item does not exist in patron's collection, true otherwise
bool Patron::returnItem(Item *item)
{
    for (int i = 0; i < checkedOutItems.size(); i++)
    {
        if (item == checkedOutItems[i])
        {
            checkedOutItems.erase(checkedOutItems.begin() + i);
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// updateHistory
// Adds action and associated item to user's history
void Patron::updateHistory(Action *addAction)
{
    history.push_back(addAction);
}

//---------------------------------------------------------------------------
// viewHistory
// Displays the checkout history for the patron, displays error message if
// user has no history
void Patron::viewHistory() const
{
    if (history.size() == 0)
    {
        cout << "Patron " << idNumber << " has no history of transactions"
             << endl;
    }
    else
    {
        cout << "Patron " << idNumber << "'s history:" << endl;
        for (int i = 0; i < history.size(); i++)
        {
            history[i]->displayCommandType();
        }
    }
}