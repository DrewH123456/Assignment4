// Hashtable is a container that hashes and stores patron pointers
// Drew Higginbotham

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
using namespace std;

/*
 * HashTable: The HashTable class is a hashtable that stores Patron pointers
 * This class provides methods for inserting, displaying a given patron, and
 * retrieving a patron
 *
 * Implementation and Notes:
 *   --This HashTable is implemented as a perfect hash table, where no collision
 *   occurs and the index of the patron lines up 1 to 1 with the index of hash
 *   tables array of patrons
 *   --Contains up to 10000 patrons in patronTable[] array, from 0-9999
 *   Error checks to ensure no patrons with negative ids or ids > 9999 are
 *   inserted
 *   --Deals with duplicates by deleting patron and not allowing it to be
 *   inserted
 */

class Patron;

class HashTable
{
private:
    Patron *patronTable[10000]{nullptr};

public:
    // Destructor, deletes all elements in patronTable that are not nullptr
    ~HashTable();

    // takes id and adds patron to patronTable[] if id 0-9999 and if not
    // a duplicate
    bool insert(int key, Patron *value);

    // displays the patron's information as well as their history
    // only used to troubleshoot
    void display() const;

    // with a given id, retrieves a patron that belongs to the index of
    // patronTable, aka owns that id
    Patron *retrieveUser(int id) const;
};

#endif