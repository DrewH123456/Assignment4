#include "nodedata.h"

//----------------------------------------------------------------------------
// constructors/destructor

NodeData::NodeData() { data = nullptr; } // default

NodeData::~NodeData() { delete data; } // needed so strings are deleted properly

NodeData::NodeData(const NodeData &nd) { data = nd.data; } // copy

NodeData::NodeData(Item *i) { data = i; } // set item as data

//----------------------------------------------------------------------------
// print
void NodeData::print(ostream &cout) const
{
    data->print(cout);
}

//----------------------------------------------------------------------------
// returns item data as pointer
Item *NodeData::returnData() const
{
    // cout << yo << endl;
    // data->print(cout);
    return data;
}

//----------------------------------------------------------------------------
// operator=

NodeData &NodeData::operator=(const NodeData &rhs)
{
    if (this != &rhs)
    {
        data = rhs.data;
    }
    return *this;
}

//----------------------------------------------------------------------------
// operator==,!=

bool NodeData::operator==(const NodeData &rhs) const
{
    return data == rhs.data;
}

bool NodeData::operator!=(const NodeData &rhs) const
{
    return data != rhs.data;
}

//----------------------------------------------------------------------------
// operator<,>,<=,>=

bool NodeData::operator<(const NodeData &rhs) const
{
    return data < rhs.data;
}

bool NodeData::operator>(const NodeData &rhs) const
{
    return data > rhs.data;
}

bool NodeData::operator<=(const NodeData &rhs) const
{
    return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData &rhs) const
{
    return data >= rhs.data;
}

//----------------------------------------------------------------------------
// setData
// returns true if the data is set, false when bad data, i.e., is eof

// bool NodeData::setData(istream &infile)
// {
//     getline(infile, data);
//     return !infile.eof(); // eof function is true when eof char is read
// }

//----------------------------------------------------------------------------
// operator<<

ostream &operator<<(ostream &output, const NodeData &nd)
{
    output << nd.data;
    return output;
}