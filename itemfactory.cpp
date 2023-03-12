/*
 * This is a factory for class Item
 * The factory will produce different children objects of Item for the library
 * to create
 */

#include "itemfactory.h"
#include "childrenbook.h"
#include "fiction.h"
#include "periodical.h"
#include "item.h" // unsure if include
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// ItemFactory
// Constructs ItemFactory, and its objFactory array. Each item child
// object being inserted lines up with the numerical version of that letter,
// with 'C' for "Children" starting at 2 for example.
ItemFactory::ItemFactory()
{
    for (int i = 0; i < 26; i++)
    {
        objFactory[i] = nullptr;
    }
    objFactory[2] = new ChildrenBook();
    objFactory[5] = new Fiction();
    objFactory[15] = new Periodical();
}

//---------------------------------------------------------------------------
// ~ItemFactory
ItemFactory::~ItemFactory()
{
    {
        for (int i = 0; i < 26; i++)
        {
            if (objFactory != nullptr)
            {
                delete objFactory[i];
                objFactory[i] = nullptr;
            }
        }
    }
}

//---------------------------------------------------------------------------
// createIt
Item *ItemFactory::createIt(char ch) const
{
    int subscript = hash(ch); // would do error checking
    if (subscript == -1)
    {
        return nullptr;
    }
    return objFactory[subscript]->create();
}

//---------------------------------------------------------------------------
// hash
// hashes letter into index by subtracting 'A'. Error checks if
// letter in 'A-Z' range
int ItemFactory::hash(char ch) const
{
    if (ch != 'C' && ch != 'F' && ch != 'P')
    {
        cout << "ERROR: '" << ch << "' is not a valid LibItem type." << endl;
        return -1;
    }
    return ch - 'A';
}