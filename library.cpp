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

Library::Library()
{
    itemContain = new ItemContainer();
    userTable = new HashTable();
    itemFac = new ItemFactory();
    actionFac = new ActionFactory();
}

Library::~Library()
{
    delete itemContain;
}

void Library::readItems()
{
    // reads in file
    string fileName = "data4books.txt";
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "File could not be opened." << endl;
    }
    char itemType;
    // for each line in txt file, call setData
    while (true)
    {
        inputFile >> itemType;
        if (inputFile.eof())
            break;
        Item *currentItem = itemFac->createIt(itemType);
        if (currentItem != nullptr)
        {
            currentItem->setData(inputFile);
            itemContain->addItem(itemType, currentItem);
        }
        string dummy;
        getline(inputFile, dummy, '\n');
    }
    inputFile.close();
}

void Library::displayItems() const
{
    itemContain->printTrees();
}

void Library::readUsers()
{
    // reads in file
    string fileName = "data4patrons.txt";
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "File could not be opened." << endl;
    }
    // for each line in txt file, call setData
    bool endOfFile = false;
    while (!endOfFile)
    {
        char dummy = inputFile.peek();
        if (inputFile.eof())
        {
            endOfFile = true;
        }
        if (!endOfFile)
        {
            Patron *currentPatron = new Patron();
            currentPatron->setData(inputFile);
            // insert deletes currentPatron if invalid ID or duplicate
            userTable->insert(currentPatron->getId(), currentPatron);
        }
    }
    inputFile.close();
}

void Library::readActions()
{
    string fileName = "data4commands.txt";
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "File could not be opened." << endl;
    }
    char commandType;
    // for each line in txt file, call setData
    while (true)
    {
        inputFile >> commandType;
        if (inputFile.eof())
        {
            break;
        }
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
        string dummy;
        getline(inputFile, dummy, '\n');
    }
    inputFile.close();
}

void Library::displayUsers() const
{
    userTable->display();
}

Patron *Library::retrieveUser(int id) const
{
    return userTable->retrieveUser(id);
}

Item *Library::retrieveItem(Item *obj) const
{
    return itemContain->retrieveItem(obj);
}
