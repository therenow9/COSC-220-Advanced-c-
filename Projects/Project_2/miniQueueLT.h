#ifndef MINIQUEUELT_H
#define MINIQUEUELT_H
#include <iostream>
#include <list>
#include <iterator>
#include "d_except.h"
template <class DataType>
class miniQueueLT
{
private:

    std::list<DataType> content;
    int elementCount; // number of elements in the stack

public:
    miniQueueLT(); // constructor create a stack with size zero
    ~miniQueueLT(); // destructor
    int size() const; // return the number of elements in the queue
    bool IsEmpty() const; // check empty queue
    void enqueue (const DataType & ); // push a node in the stack
    void PrintQueue() const; // print all queue content (TOP to BOTTOM)
    void dequeue(); // return an element from the front of queue
// Issue exception if the stack is empty
    DataType& front(); // Return Data from the top of the queue.
// Issue exception if the stack is empty
    const DataType& front() const; // Return Data from the top of the queue.
// Issue exception if the queue is empty

};

#include "miniQueueLT.cpp"
#endif
