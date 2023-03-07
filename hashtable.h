/*
 * This is a class that stores all of the users into a hash table
 * Hash Table is array of Patron pointers with one index for max num of possible
 * users. Deals with duplicates and has no collision
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
using namespace std;

class Patron;

class HashTable
{
private:
    Patron *patronTable[10000]{nullptr};

public:
    // HashTable functions
    bool insert(int key, Patron *value);
    // int hash(int id) const; // hash function

    void display() const;
};

#endif