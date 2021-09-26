#include "miniQueueLT.h"

template <class DataType>
miniQueueLT<DataType>::miniQueueLT()
{
    elementCount = 0;
    //set element count to 0
}

template <class DataType>
int miniQueueLT<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniQueueLT<DataType>::IsEmpty() const
{
    bool empt;
    if(elementCount == 0)
    {
        empt=true;
    }
    else
    {
        empt= false;
    }
    return empt;
}
template <class DataType>
miniQueueLT<DataType>::~miniQueueLT()
{
    content.clear();
}

template <class DataType>
void miniQueueLT<DataType>::enqueue (const DataType & c)
//change this one
{
    elementCount ++;
    content.push_back(c);
}

template <class DataType>
void miniQueueLT<DataType>::PrintQueue () const
{
    class list<DataType>::const_iterator iter;
    for(iter = content.begin(); iter != content.end(); iter++)
    {
        cout << *iter << " ";
    }
    //Declare list and print out each value
}


template <class DataType>
void miniQueueLT<DataType>::dequeue()
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    elementCount --;
    content.pop_front();
    //subtract from element count and pop out the front
}


template <class DataType>
DataType& miniQueueLT<DataType>::front()
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content.front();
    //return first element
}

template <class DataType>
const DataType& miniQueueLT<DataType>::front() const
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content.front();
    //return first element
}

