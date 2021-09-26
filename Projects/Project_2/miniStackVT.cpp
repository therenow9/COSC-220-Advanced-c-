#include "miniStackVT.h"

template <class DataType>
miniStackVT<DataType>::miniStackVT()
//constructor
{
    elementCount = 0;
}

template <class DataType>
miniStackVT<DataType>::~miniStackVT()
//destructor
{
    for(int i  = 0; i < content.size(); i++)
    {
        content.erase(content.begin());
    }
}

template <class DataType>
int miniStackVT<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniStackVT<DataType>::IsEmpty() const
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
void miniStackVT<DataType>::Pop()
{
    if (elementCount==0)
    {
        throw underflowError("miniStack pop is empty");
    }
    elementCount --;
    content.erase(content.begin());
    //erase from beginning
}


template <class DataType>
void miniStackVT<DataType>::Push (const DataType & c)
{
    elementCount += 1;
    content.insert(content.begin(), c);
}

template <class DataType>
void miniStackVT<DataType>::PrintStack () const
{
    for(int i  = 0; i< content.size(); i++)
        std::cout << content[i] << " ";
}

template <class DataType>
DataType& miniStackVT<DataType>::TopStack()
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content[0];
}
template <class DataType>
const DataType& miniStackVT<DataType>::TopStack() const
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content[0];
}

