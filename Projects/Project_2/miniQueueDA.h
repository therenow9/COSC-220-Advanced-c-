#ifndef MINIQUEUEDA_H
#define MINIQUEUEDA_H
#include <iostream>
#include "d_except.h"
template <class DataType>
class miniQueueDA
{
private:
     DataType *content; // for DA
    int elementCount; // number of elements in the queue

public:
    miniQueueDA(); // constructor create a queue with size zero
    ~miniQueueDA(); // destructor
    int size() const; // return the number of elements in the queue
    bool IsEmpty() const; // check empty queue
    void enqueue (const DataType & ); // push a node in the queue
    void PrintQueue() const; // print all stack content (TOP to BOTTOM)
    void dequeue(); // take an element from the top of queue.
// Issue exception if the queue is empty
    DataType& front(); // Return Data from the top of the queue.
// Issue exception if the queue is empty
    const DataType& front() const; // Return Data from the top of the queue.
// Issue exception if the queue is empty

};

#include "miniQueueDA.cpp"
#endif
