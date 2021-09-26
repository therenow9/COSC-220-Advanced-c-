#include "miniStackLT.h"

template <class DataType>
miniStackLT<DataType>::miniStackLT()
{
    elementCount = 0;
    //set element count to 0
}

template <class DataType>
int miniStackLT<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniStackLT<DataType>::IsEmpty() const
{
    bool empt;
    if(elementCount == 0){
        empt=true;
    }
    else{
        empt= false;
    }
    return empt;
}
template <class DataType>
miniStackLT<DataType>::~miniStackLT()
{
    content.clear();
}

template <class DataType>
void miniStackLT<DataType>::Push (const DataType & c)
{
    elementCount ++;
    content.push_front(c);
}

template <class DataType>
void miniStackLT<DataType>::PrintStack () const
{
    class list<DataType>::const_iterator iter;
    for(iter = content.begin(); iter != content.end(); iter++){
        cout << *iter << " ";
    }
    //Declare list and print out each value
}


template <class DataType>
void miniStackLT<DataType>::Pop()
{
     if (elementCount==0)
    {
        throw underflowError("miniStack pop is empty");
    }
    elementCount --;
    content.pop_front();
    //subtract from element count and pop out the front
}


template <class DataType>
DataType& miniStackLT<DataType>::TopStack()
{
     if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content.front();
    //return first element
}

template <class DataType>
const DataType& miniStackLT<DataType>::TopStack() const
{
     if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content.front();
    //return first element
}

