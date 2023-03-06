/*
 * This is a library class that manages users and books and keeps track
 * their relationship to one another. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * and users to one another
 */

#include "library.h"
#include "itemfactory.h"
#include "item.h"
#include "itemcontainer.h"
#include <iostream>
#include <fstream>
using namespace std;

Library::Library()
{
    ItemContainer *tempContainer = new ItemContainer();
    itemContain = tempContainer;
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
    }
    inputFile.close();
}

void Library::displayBooks() const
{
    itemContain->printTrees();
}