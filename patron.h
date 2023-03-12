// A Patron is a member of the library and can make transactions of items
// Drew Higginbotham

#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Item;
class Action;

/* Patron: The Patron class represents a library patron. Each patron has a
 * unique identifier, a name, a collection of books they are checking out,
 * and their history of transactions
 * The Patron can check out a book, return a book, and view their checkout
 * history.
 *
 * Implementation and Assumptions:
 *   --Each patron has an id from 0-9999
 *   --Patron's history is stored as a vectory of action pointers
 *   --Patron's currrently checked out Items is stored as item pointers
 */

class Patron
{
private:
    int idNumber;                   // patron's id
    string lastName;                // patron's last name
    string firstName;               // patron's first name
    vector<Item *> checkedOutItems; // patron's currently checked out items
    vector<Action *> history;       // patron's history of transactions

public:
    // Default constructor
    Patron(){};

    // Destructor, deletes patron's history of transactions
    ~Patron();

    // sets patron's data using info from line in infile from data4patrons.txt
    void setData(ifstream &inputFile);

    // sets patron's data using info from line in infile from data4commands.txt
    void setDataCommand(ifstream &inputFile);

    // Returns the unique identifier for the patron
    int getId() const;

    // Returns the last name of the patron
    string getLastName() const;

    // Returns the first name of the patron
    string getFirstName() const;

    // Adds a item to the list of items checked out by the patron
    void checkOutItem(Item *item);

    // Removes an item from the list of items checked out by the patron
    // returns false if item doesn't exist in patron's collection, trueotherwise
    bool returnItem(Item *item);

    // Displays the checkout history for the patron, displays error message if
    // user has no history
    void viewHistory() const;

    // Displays patron's id and name
    void print() const;

    // Display patron's borrowed items
    void displayItems() const;

    // Adds action and associated item to user's history
    void updateHistory(Action *addAction);
};

#endif