// Hashtable is a container that hashes and stores patron pointers
// Drew Higginbotham

/*
 * This is a class that stores all of the users into a hash table
 * Hash Table is array of Patron pointers with one index for max num of possible
 * users. Deals with duplicates and has no collision
 */

#include "hashtable.h"
#include "patron.h"
#include <iostream>
using namespace std;

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