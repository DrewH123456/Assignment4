/*
 * This is a factory for class Action
 * The factory will produce different children objects of action for the library
 * to create, allowing the action to be executed when the action is processed
 */

#include "actionfactory.h"
#include "checkout.h"
#include "display.h"
#include "history.h"
#include "return.h"
#include "action.h" // unsure if include
#include <iostream>
using namespace std;

ActionFactory::ActionFactory()
{
    for (int i = 0; i < 26; i++)
    {
        objFactory[i] = nullptr;
    }
    objFactory[2] = new CheckOut();
    objFactory[3] = new Display();
    objFactory[7] = new History();
    objFactory[17] = new Return();
}
ActionFactory::~ActionFactory()
{
    {
        for (int i = 0; i < 26; i++)
        {
            delete objFactory[i];
            objFactory[i] = nullptr;
        }
    }
}

Action *ActionFactory::createIt(char ch) const
{
    int subscript = hash(ch); // would do error checking
    if (subscript == -1)
    {
        return nullptr;
    }
    return objFactory[subscript]->create();
}

int ActionFactory::hash(char ch) const
{
    if (ch != 'C' && ch != 'D' && ch != 'H' && ch != 'R')
    {
        cout << "ERROR: '" << ch << "' is not a valid action type." << endl;
        return -1;
    }
    return ch - 'A';
}