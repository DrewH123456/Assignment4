// Library stores items and patrons and allows transactions to occur
// Drew Higginbotham

/*
 * This is a library class that manages users and books and keeps track
 * their relationship to one another. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * and users to one another
 */

#include "library.h"
#include "itemfactory.h"
#include "actionfactory.h"
#include "item.h"
#include "action.h"
#include "itemcontainer.h"
#include "hashtable.h"
#include "patron.h"
#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------
// Library
// Constructor, constructs containers and factories
Library::Library()
{
    itemContain = new ItemContainer();
    userTable = new HashTable();
    itemFac = new ItemFactory();
    actionFac = new ActionFactory();
}

//---------------------------------------------------------------------------
// ~Library
// Destructor, deletes containers and factories
Library::~Library()
{
    delete itemContain;
    delete userTable;
    delete itemFac;
    delete actionFac;
}

//---------------------------------------------------------------------------
// readItems
// reads in data4books.txt, reading and processing each line until end of
// file. error checks if item being created is of a valid item type
// stores created item into itemContain container
void Library::readItems()
{
    // reads in file
    string fileName = "data4books.txt";
    ifstream inputFile(fileName);
    if (!inputFile) // if invalid file
    {
        cout << "File could not be opened." << endl;
    }
    char itemType;
    // for each line in txt file, call setData
    while (true)
    {
        inputFile >> itemType; // takes in type of item
        if (inputFile.eof())   // checks if end of file
            break;
        // creates new item if valid item type
        Item *currentItem = itemFac->createIt(itemType);
        if (currentItem != nullptr) // if valid item type
        {
            currentItem->setData(inputFile);             // sets data members
            itemContain->addItem(itemType, currentItem); // adds to itemContain
        }
        string dummy; // skips to next line
        getline(inputFile, dummy, '\n');
    }
    inputFile.close();
}

//---------------------------------------------------------------------------
// displayItems
// displays all items of library in sorted order, calling on itemContain's
// displayItems
void Library::displayItems() const
{
    itemContain->printTrees();
}

void Library::readUsers()
{
    string fileName = "data4patrons.txt";
    ifstream inputFile(fileName);
    if (!inputFile) // if invalid file
    {
        cout << "File could not be opened." << endl;
    }
    // for each line in txt file, call setData
    bool endOfFile = false;
    while (!endOfFile)
    {
        char dummy = inputFile.peek(); // triggers eof to being true or false
        if (inputFile.eof())
        {
            endOfFile = true;
        }
        if (!endOfFile)
        {
            // creates patron object which gets deleted in userTable->insert
            // if invalid id
            Patron *currentPatron = new Patron();
            // setData takes care of skipping to next line
            currentPatron->setData(inputFile); // assigns patron an id
            // insert deletes currentPatron if invalid ID or duplicate
            userTable->insert(currentPatron->getId(), currentPatron);
        }
    }
    inputFile.close();
}

//---------------------------------------------------------------------------
// readActions
// reads in data4commands.txt, reading and processing each line until end of
// file. error checks if action being created is of a valid action type
// error checks if data from given patron or item are valid
void Library::readActions()
{
    string fileName = "data4commands.txt";
    ifstream inputFile(fileName);
    if (!inputFile) // if invalid textfile
    {
        cout << "File could not be opened." << endl;
    }
    char commandType;
    // for each line in txt file, call setData
    while (true)
    {
        inputFile >> commandType; // assigns command type as char
        if (inputFile.eof())
        {
            break;
        }
        // creates action pointer to given action object, nullptr if invalid
        Action *currentAction = actionFac->createIt(commandType);
        // if a valid command type
        if (currentAction != nullptr)
        {
            // if valid data
            if (currentAction->setData(inputFile, itemFac))
            {
                // if execution failed. deletes invalid checkouts and returns,
                // deletes all history and displays
                if (!currentAction->execute(this))
                {
                    delete currentAction;
                    currentAction = nullptr;
                }
            }
            else // if invalid data
            {
                delete currentAction;
                currentAction = nullptr;
            }
        }
        string dummy; // skips to next line
        getline(inputFile, dummy, '\n');
    }
    inputFile.close();
}

//---------------------------------------------------------------------------
// displayUsers
// displays all users of library in sorted order, calling on userTable's
// displayItems
void Library::displayUsers() const
{
    userTable->display();
}

//---------------------------------------------------------------------------
// retrieveUser
// displays all users of library in sorted order, calling on userTable's
// displayItems
Patron *Library::retrieveUser(int id) const
{
    return userTable->retrieveUser(id);
}

//---------------------------------------------------------------------------
// retrieveItem
// displays all items of library in sorted order, calling on itemContain's
// displayItems
Item *Library::retrieveItem(Item *obj) const
{
    return itemContain->retrieveItem(obj);
}
