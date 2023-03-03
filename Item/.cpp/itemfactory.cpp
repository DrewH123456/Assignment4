/*
 * This is a factory for class Item
 * The factory will produce different children objects of Item for the library
 * to create
 */

#include "itemfactory.h"
#include "childrenbook.h"
#include "fiction.h"
#include "periodical.h"
#include <iostream>
using namespace std;

class Item;

ItemFactory::ItemFactory()
{
    objFactory[0] = new ChildrenBook();
    objFactory[1] = new Fiction();
    objFactory[2] = new Periodical();
    for (int i = 3; i < 10; i++)
    {
        objFactory[i] = NULL;
    }
}
ItemFactory::~ItemFactory()
{
    {
        for (int i = 0; i < 3; i++)
        {
            delete objFactory[i];
            objFactory[i] = NULL;
        }
    }
}

Item *ItemFactory::createIt(char ch) const
{
    int subscript = hash(ch); // would do error checking
    if (subscript == -1)
    {
        return nullptr;
    }
    return objFactory[subscript]->create();
}

int ItemFactory::hash(char ch) const
{
    if (ch != 'C' && ch != 'F' && ch != 'P')
    {
        cout << "ERROR: '" << ch << "' is not a valid LibItem type.";
        return -1;
    }
    return ch - 'A';
}