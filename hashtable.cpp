// Hashtable is a container that hashes and stores patron pointers
// Drew Higginbotham

#include "hashtable.h"
#include "patron.h"
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// ~HashTable
// Destructor, deletes all elements in patronTable that are not nullptr
HashTable::~HashTable()
{
    for (int i = 0; i < 10000; i++)
    {
        if (patronTable[i] != nullptr)
        {
            delete patronTable[i];
        }
    }
}

//---------------------------------------------------------------------------
// insert
// takes id and adds patron to patronTable[] if id 0-9999 and if not
// a duplicate
bool HashTable::insert(int id, Patron *patron)
{
    if (id > 9999 || id < 0) // if a valid id 0-9999
    {
        delete patron;
        patron = nullptr;
        cout << id << " is an invalid ID" << endl;

        return false;
    }
    if (patronTable[id] != nullptr) // takes care of duplicates
    {
        delete patron;
        patron = nullptr;
        cout << "Patron with id: " << id << " already inserted." << endl;
        return false;
    }
    patronTable[id] = patron; // inserts patron into patronTable[] successfully
    return true;
}

//---------------------------------------------------------------------------
// display
// displays the patron's information as well as their history
// only used to troubleshoot
void HashTable::display() const
{
    cout << "Displaying Patrons:" << endl; // displays each patron's information
    for (int i = 0; i < 10000; i++)
    {
        if (patronTable[i] != nullptr)
        {
            patronTable[i]->print();
            patronTable[i]->displayItems();
        }
    }
}

//---------------------------------------------------------------------------
// retrieveUser
// with a given id, retrieves a patron that belongs to the index of
// patronTable, aka owns that id
Patron *HashTable::retrieveUser(int id) const
{
    if (id < 0 || id > 9999) // ensures valid id, 0-9999
    {
        return nullptr;
    }
    return patronTable[id];
}