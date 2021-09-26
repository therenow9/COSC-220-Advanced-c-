#ifndef MINIQUEUEDL_H
#define MINIQUEUEDL_H
#include <iostream>
#include "d_except.h"
#include "Dnode.h"

template <class DataType>
class miniQueueDL
{
private:
    Dnode<DataType>* head; // DL

    int elementCount; // number of elements in the queue

public:
    miniQueueDL(); // constructor create a queue with size zero
    ~miniQueueDL(); // destructor
    int size() const; // return the number of elements in the queue
    bool IsEmpty() const; // check empty queue
    void enqueue (const DataType & ); // push a node in the queue
    void PrintQueue() const; // print all queue content (TOP to BOTTOM)
    void dequeue(); // Pop an element from the top of queue
// Issue exception if the stack is empty
    DataType& front(); // Return Data from the top of the queue
// Issue exception if the stack is empty
    const DataType& front() const; // Return Data from the top of the queue.
// Issue exception if the stack is empty

};
#include "miniQueueDL.cpp"
#endif
