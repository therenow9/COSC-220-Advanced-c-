#ifndef MINISTACKLT_H
#define MINISTACKLT_H

#include <iostream>
#include <list>
#include <iterator>
#include "d_except.h"
template <class DataType>
class miniStackLT
{
private:
     std::list<DataType> content;
    int elementCount; // number of elements in the stack

public:
    miniStackLT(); // constructor create a stack with size zero
    ~miniStackLT(); // destructor
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
#include "miniStackLT.cpp"
#endif

