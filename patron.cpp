/** The Patron class represents a library patron. Each patron has a unique
 * identifier, a name, and a list of books they have checked out. The Patron
 * can check out a book, return a book, and view their checkout history.
 **/

#include "patron.h"
#include "action.h"
#include "item.h"

Patron::~Patron()
{
    for (int i = 0; i < history.size(); i++)
    {
        delete history[i];
        history[i] = nullptr;
    }
};

void Patron::setData(ifstream &inputFile)
{
    string dummy; // used in final getLine to move inputFile to next line

    inputFile >> idNumber;
    inputFile >> lastName;
    inputFile >> firstName;
    getline(inputFile, dummy, '\n');
}

void Patron::setDataCommand(ifstream &inputFile)
{
    inputFile >> idNumber;
}

int Patron::getId() const
{
    return idNumber;
}

string Patron::getLastName() const
{
    return lastName;
}

string Patron::getFirstName() const
{
    return firstName;
}

void Patron::print() const
{
    cout << idNumber << ": " << lastName << ", " << firstName << endl;
}

void Patron::displayItems() const
{
    for (int i = 0; i < checkedOutItems.size(); i++)
    {
        checkedOutItems[i]->individualPrint();
    }
}

// item added to patron's checkedOutItems collection
void Patron::checkOutItem(Item *addItem)
{
    checkedOutItems.push_back(addItem);
}

// Removes a item from the list of items checked out by the patron
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

void Patron::updateHistory(Action *addAction)
{
    history.push_back(addAction);
}

void Patron::viewHistory() const
{
    if (history.size() == 0)
    {
        cout << "Patron " << idNumber << " has no history of transactions"
             << endl;
    }
    else
    {
        cout << "Patron's history:" << endl;
        for (int i = 0; i < history.size(); i++)
        {
            history[i]->display();
        }
    }
}