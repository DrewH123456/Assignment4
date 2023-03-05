/*
 * This is a class that stores all of the users into a hash table
 * Has various hash table functions such as contains, insert, remove
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

class HashTable
{
private:
    vector<int> tableVector;
    int size;

public:
    // Constructor
    HashTable();

    // Destructor
    ~HashTable();

    // HashTable functions
    bool contains(int key) const;
    bool insert(int key, User *value);
    bool remove(int key);
    void clear();
    int size() const;
    bool isEmpty() const;

    int hash(int id) const; // hash function
};

#endif