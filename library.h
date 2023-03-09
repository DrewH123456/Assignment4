/*
 * This is a library class that manages users and books and keeps track
 * their relationship to one another. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * and users to one another
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
class ItemFactory;
class ActionFactory;
class ItemContainer;
class HashTable;
class Patron;
class Book;

class Library
{
private:
    // Factories
    ActionFactory *actionFac;
    ItemFactory *itemFac;

    // Containers
    ItemContainer *itemContain;
    HashTable *userTable;

public:
    // Constructor
    Library();

    // Destructor
    ~Library();

    // processes text files
    void readUsers();
    void readItems();
    void readActions();

    // retrieves patron based on id
    Patron *retrieveUser(int id) const;

    // retrieves book based on title and author
    Item *retrieveItem(Item *obj) const;

    void displayItems() const;

    void displayUsers() const;
};
#endif