#include <iostream>
#include <vector>
#include "miniQueueVT.h"

template <class DataType>
miniQueueVT<DataType>::miniQueueVT()
//constructor
{
    elementCount = 0;
}

template <class DataType>
miniQueueVT<DataType>::~miniQueueVT()
//destructor
{
    for(int i  = 0; i < content.size(); i++)
    {
        content.erase(content.begin());
    }
}

template <class DataType>
int miniQueueVT<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniQueueVT<DataType>::IsEmpty() const
{
    bool empt;
    if(elementCount == 0)
    {
        empt= true;
    }
    else
    {
        empt= false;
    }
    return empt;
}

template <class DataType>
void miniQueueVT<DataType>::dequeue()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue front is empty");
    }
    elementCount --;
    content.erase(content.begin());
    //erase from beginning
}


template <class DataType>
void miniQueueVT<DataType>::enqueue (const DataType & c)
{
    elementCount += 1;
    content.insert(content.end(), c);
}

template <class DataType>
void miniQueueVT<DataType>::PrintQueue () const
{
    for(int i  = 0; i< content.size(); i++)
        std::cout << content[i] << " ";
}

template <class DataType>
DataType& miniQueueVT<DataType>::front()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue front is empty");
    }
    return content[0];
    //return first element of content array
}
template <class DataType>
const DataType& miniQueueVT<DataType>::front() const
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue front is empty");
    }
    return content[0];
    //return first element of content array
}
