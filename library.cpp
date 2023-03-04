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
#include <istream>
#include <iostream>
#include <fstream>
using namespace std;

void Library::readItems()
{
    string fileName = "data4books.txt";
    ifstream inputFile(fileName);
    char itemType;
    while (true)
    {
        inputFile >> itemType;
        if (inputFile.eof())
            return;
        Item *currentItem = itemFac->createIt(itemType);
        if (currentItem != nullptr)
        {
            currentItem->setData(inputFile);
            ItemContainer->addItem(itemType, currentItem);
        }
    }
}