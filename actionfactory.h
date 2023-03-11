// An Action Factory creates and returns instances of child actions
// Drew Higginbotham

#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

/*
 * ActionFactory: The ActionFactory class creates and returns instances of
 * children actions, checkout, return, display, and history, given a single
 * character. This allows for the action to be executed when the action is
 * processed.
 *
 * Implementation and Notes:
 *   --Contains array objFactory which stores an instance of each object type
 *   --To create an instance of the object, calls create() on child action from
 *   objFactory array and returns it
 *   --hashes inputted letter and assigns it a number to search within the
 *   objFactory array to return an instance of the desired action
 */

class Action;

class ActionFactory
{
private:
    Action *objFactory[26];  // contains array of each object
    int hash(char ch) const; // hash function

public:
    // Constructs ActionFactory, and its objFactory array. Each action child
    // object being inserted lines up with the numerical version of that letter,
    // with 'C' for "Checkout" starting at 2 for example.
    ActionFactory();

    // Deletes all indexes of objFactory array that are not nullptr already.
    ~ActionFactory();

    // translates character to index using hash(), searches for action within
    // objFactory array and returns instance of child action using create()
    Action *createIt(char c) const;
};

#endif