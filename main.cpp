#include "library.h"
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

    return 0;
}