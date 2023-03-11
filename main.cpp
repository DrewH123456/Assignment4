#include "childrenbook.h"
#include "fiction.h"
#include "periodical.h"
#include "library.h"
#include "itemfactory.h"
#include "checkout.h"
#include "return.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Library *l = new Library();
    l->readItems();
    l->readUsers();
    l->readActions();
    delete l;
    // CheckOut *c = new CheckOut();
    // ItemFactory *i = new ItemFactory();
    // ifstream inputFile;
    // inputFile.open("data4commands.txt");
    // char e;
    // inputFile >> e;
    // c->setData(inputFile, i);
    // c->execute(l);
    // l->displayUsers();

    // Return *r = new Return();
    // inputFile >> e;
    // r->setData(inputFile, i);
    // r->execute(l);
    // l->displayUsers();

    return 0;
}