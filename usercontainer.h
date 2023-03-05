/*
 * This is a class that contains all of the users of the library
 * It stores each type of user in a separate hash table
 * All of the hash tables are stored in a map
 */

#ifndef USERCONTAINER_H
#define USERCONTAINER_H

#include "hashtable.h"
#include <map>

class UserContainer
{
private:
    map<char, HashTable *> hashTables; // stores hashtables of different users

public:
    // Constructor
    UserContainer();

    // Destructor
    ~UserContainer();

    // inserts a new hashTable and associates character with it
    void addTable(char, HashTable *);
    void removeTable(char);
};

#endif