#ifndef MINIQUEUEVT_H
#define MINIQUEUEVT_H
#include <iostream>
#include <vector>
#include "d_except.h"
template <class DataType>
class miniQueueVT
{
private:

    std::vector<DataType> content;
    int elementCount; // number of elements in the queue

public:
    miniQueueVT(); // constructor create a stack with size zero
    ~miniQueueVT(); // destructor
    int size() const; // return the number of elements in the queue
    bool IsEmpty() const; // check empty queue
    void enqueue (const DataType & ); // push a node in the stack
    void PrintQueue() const; // print all Queue content (TOP to BOTTOM)
    void dequeue(); // remove an element from the front of the queue.
// Issue exception if the queue is empty
    DataType& front(); // Return Data from the top of the queue.
// Issue exception if the queue is empty
    const DataType& front() const; // Return Data from the top of the queue.
// Issue exception if the queue is empty

};

#include "miniQueueVT.cpp"
#endif
