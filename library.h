// Library stores items and patrons and allows transactions to occur
// Drew Higginbotham

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
#include <fstream>
class ItemFactory;
class ActionFactory;
class ItemContainer;
class HashTable;
class Patron;
class Item;

/*
 * Library: The Library class manages patrons and items and keeps track
 * of patron's relationships to its items. It performs actions based on what it
 * reads from the text file it receives in readActions() to assign books
 * to patrons and change the stock accordingly.
 *
 * Implementation and Assumptions:
 *   --The Library class assumes that the format of data4books, data4patrons,
 *   and data4commands are consistent, but error checks them as necessary
 *   --Properly manages the memory of each item, patron, factory, and container
 *   created and used
 *   --displayUsers not actually used in program, only for troubleshooting
 *   --follows proper open closed design principle, allowing for extension
 *   --makes use of factories rather than switches, allowing for code to be
 *   --changed in outside classes rather than clustered in the library class
 */

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
    // Constructor, constructs containers and factories
    Library();

    // Destructor, deletes containers and factories
    ~Library();

    // reads in data4patrons.txt, reading and processing each line until end of
    // file. error checks if user being created is within 0-9999 range.
    // stores created item into userTable if valid
    void readUsers();

    // reads in data4books.txt, reading and processing each line until end of
    // file. error checks if item being created is of a valid item type
    // stores created item into itemContain container if valid
    void readItems();

    // reads in data4commands.txt, reading and processing each line until end of
    // file. error checks if action being created is of a valid action type
    // error checks if data from given patron or item are valid
    void readActions();

    // retrieves patron based on id, calling on userTable's retrieveUser
    Patron *retrieveUser(int id) const;

    // retrieves item from respective binTree, calling on itemContain's
    // retrieveItem
    Item *retrieveItem(Item *obj) const;

    // displays all items of library in sorted order, calling on itemContain's
    // displayItems
    void displayItems() const;

    // displays all users of library in sorted order, calling on userTable's
    // displayItems
    void displayUsers() const;
};
#endif