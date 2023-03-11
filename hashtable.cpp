/*
 * This is a class that stores all of the users into a hash table
 * Hash Table is array of Patron pointers with one index for max num of possible
 * users. Deals with duplicates and has no collision
 */

#include "hashtable.h"
#include "patron.h"
#include <iostream>
using namespace std;

bool HashTable::insert(int id, Patron *patron)
{
    if (id > 9999 || id < 0)
    {
        delete patron;
        patron = nullptr;
        cout << id << " is an invalid ID" << endl;

        return false;
    }
    if (patronTable[id] != nullptr)
    {
        delete patron;
        patron = nullptr;
        cout << "Patron with id: " << id << " already inserted." << endl;
        return false;
    }
    patronTable[id] = patron;
    return true;
}

void HashTable::display() const
{
    cout << "Displaying Patrons:" << endl;
    for (int i = 0; i < 10000; i++)
    {
        if (patronTable[i] != nullptr)
        {
            patronTable[i]->print();
            patronTable[i]->displayItems();
        }
    }
}

Patron *HashTable::retrieveUser(int id) const
{
    if (id < 0 || id > 9999)
    {
        return nullptr;
    }
    return patronTable[id];
}