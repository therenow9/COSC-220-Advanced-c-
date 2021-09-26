#ifndef MINISTACKVT_H
#define MINISTACKVT_H
#include <iostream>
#include <vector>
#include "d_except.h"
using namespace std;
template <class DataType>
class miniStackVT
{
private:
    vector<DataType> content; // for VT
    int elementCount; // number of elements in the stack

public:
    miniStackVT(); // constructor create a stack with size zero
    ~miniStackVT(); // destructor
    int size() const; // return the number of elements in the stack
    bool IsEmpty() const; // check empty stack
    void Push (const DataType & ); // push a node in the stack
    void PrintStack() const; // print all stack content (TOP to BOTTOM)
    void Pop(); // Pop an element from the top of stack.
    // Issue exception if the stack is empty
    DataType& TopStack(); // Return Data from the top of the stack.
    // Issue exception if the stack is empty
    const DataType& TopStack() const; // Return Data from the top of the stack.
    // Issue exception if the stack is empty

};

#include "miniStackVT.cpp"
#endif
