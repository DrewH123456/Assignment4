// An Action Factory creates and returns instances of child actions
// Drew Higginbotham

#include "actionfactory.h"
#include "checkout.h"
#include "display.h"
#include "history.h"
#include "return.h"
#include "action.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------------
// ActionFactory()
// Constructs ActionFactory, and its objFactory array. Each action child object
// being inserted lines up with the numerical version of that letter,
// with 'C' for "Checkout" starting at 2 for example.
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

//----------------------------------------------------------------------------
// ~ActionFactory()
// Deletes all indexes of objFactory array that are not nullptr already.
ActionFactory::~ActionFactory()
{
    {
        for (int i = 0; i < 26; i++)
        {
            if (objFactory[i] != nullptr)
            {
                delete objFactory[i];
                objFactory[i] = nullptr;
            }
        }
    }
}

//----------------------------------------------------------------------------
// hash()
// translates character to index using hash(), and searches for action within
// objFactory array and returns instance of child action using create()
Action *ActionFactory::createIt(char ch) const
{
    int subscript = hash(ch); // would do error checking
    if (subscript == -1)
    {
        return nullptr;
    }
    if (objFactory[subscript] == nullptr) // if 'A-Z' but not in objFactory
    {
        return nullptr;
    }
    return objFactory[subscript]->create(); // returns Action *
}

//----------------------------------------------------------------------------
// hash()
// translates letter into index by subtracting 'A'. Error checks if
// letter in 'A-Z' range
int ActionFactory::hash(char ch) const
{
    if (ch < 'A' || ch > 'Z')
    {
        cout << "ERROR: '" << ch << "' is not a valid action type." << endl;
        return -1;
    }
    return ch - 'A';
}