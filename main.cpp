#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Library *lib = new Library();
    lib->readItems();
    lib->readUsers();
    lib->readActions();
    delete lib;

    return 0;
}