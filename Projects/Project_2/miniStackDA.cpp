#include "miniStackDA.h"

template <class DataType>
miniStackDA<DataType>::miniStackDA()
{
    elementCount = 0;
    content=NULL;
}

template <class DataType>
miniStackDA<DataType>::~miniStackDA()
{
    if(elementCount > 1)
    {
        delete [] content;
        content = NULL;
        //if greater than 1 set content to null
    }
    else
    {
        delete content;
        content = NULL;
    }
}

template <class DataType>
bool miniStackDA<DataType>::IsEmpty() const
{//if its empty return true if its not dont

    bool empt;
    if(elementCount == 0){

        empt= true;
    }
    else{
        empt= false;
    }
        return empt;
}
template <class DataType>
int miniStackDA<DataType>::size() const
{
    return elementCount;
    //to get the size just return element count
}

template <class DataType>
void miniStackDA<DataType>::PrintStack() const
{
    for(int i = 0; i < elementCount; i++){
        cout << content[i] << " ";
    }
}

template <class DataType>
void miniStackDA<DataType>::Pop()
{
     if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    elementCount --;
    DataType *temp = new DataType[elementCount];
    //subtract element and create new data type when popping stack
    for(int i = 0; i< elementCount; i++){
        temp[i] = content[i+1];
    }
    delete []content;
    content = temp;
    //delete the content and reassign it to temp
}

template <class DataType>
void miniStackDA<DataType>::Push(const DataType & c)
{
    elementCount ++;
    DataType *temp = new DataType[elementCount];
    //increase element count and create new datatype
    for(int i = 0; i < elementCount; i++)
    {
        if(i==0){
            temp[i] = c;
        }
        else{
            temp[i] = content[i-1];
        }
    }
    delete []content;
    content = temp;
    //delete content and reassign it to temp
}
template <class DataType>
DataType& miniStackDA<DataType>::TopStack()
{
     if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content[0];
    //return first element of content array
}
template <class DataType>
const DataType& miniStackDA<DataType>::TopStack() const
{
     if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return content[0];
    //return first element of content array
}
