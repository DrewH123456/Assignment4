/*
 * This is a factory for class Item
 * The factory will produce different children objects of Item for the library
 * to create
 */

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

class Item;

class ItemFactory
{
private:
    Item *objFactory[26];    // contains array of each object
    int hash(char ch) const; // hash function

public:
    // Factory constructor, initializes objFactory
    ItemFactory();

    // Factory destructor, deletes objFactory
    ~ItemFactory();

    // Creates a corresponding action based on the information provided
    Item *createIt(char c) const;
};

#endif