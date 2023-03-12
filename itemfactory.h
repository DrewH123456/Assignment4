// An Item Factory creates and returns instances of child actions
// Drew Higginbotham

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

/*
 * ItemFactory: The ItemFactory class creates and returns instances of
 * children items: children, fiction, and periodical, given a single
 * character.
 *
 * Implementation and Notes:
 *   --Contains array objFactory which stores an instance of each object type
 *   --To create an instance of the object, calls create() on child action from
 *   objFactory array and returns it
 *   --hashes inputted letter and assigns it a number to search within the
 *   objFactory array to return an instance of the desired action
 */

class Item;

class ItemFactory
{
private:
    Item *objFactory[26]; // contains array of each object
    // hashes letter into index by subtracting 'A'.
    // Error checks if letter in 'A-Z' range
    int hash(char ch) const;

public:
    // Constructs ItemFactory, and its objFactory array. Each item child
    // object being inserted lines up with the numerical version of that letter,
    // with 'C' for "Children" starting at 2 for example.
    ItemFactory();

    // Deletes all indexes of objFactory array that are not nullptr already.
    ~ItemFactory();

    // hashes character to index using hash(), searches for item within
    // objFactory array and returns instance of child item using create()
    Item *createIt(char c) const;
};

#endif