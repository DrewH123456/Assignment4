/** The Patron class represents a library patron. Each patron has a unique
 * identifier, a name, and a list of books they have checked out. The Patron
 * can check out a book, return a book, and view their checkout history.
 **/
#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Book;

class Patron
{
private:
    int idNumber;
    string lastName;
    string firstName;
    vector<Book *> books;
    vector<Book *> history;

public:
    // Default constructor
    Patron(){};

    // Destructor
    ~Patron(){};

    // sets item's data using info from line in infile
    void setData(ifstream &inputFile);

    // Returns the unique identifier for the patron
    int getId() const;

    // Returns the last name of the patron
    string getLastName() const;

    // Returns the first name of the patron
    string getFirstName() const;

    // Adds a book to the list of books checked out by the patron
    void checkOutBook(Book *book);

    // Removes a book from the list of books checked out by the patron
    void returnBook(Book *book);

    // Displays the checkout history for the patron
    void viewHistory() const;

    // Displays patron's id and name
    void print() const;
};

#endif