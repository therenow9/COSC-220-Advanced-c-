#include "miniQueueDA.h"
template <class DataType>
miniQueueDA<DataType>::miniQueueDA()
{
    elementCount = 0;
    content=NULL;
}

template <class DataType>
miniQueueDA<DataType>::~miniQueueDA()
{
    if(content !=NULL)
    {
        delete [] content;
        content = NULL;
        //if greater than 1 set content to null
    }
}

template <class DataType>
bool miniQueueDA<DataType>::IsEmpty() const
{
    //if its empty return true if its not dont

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
int miniQueueDA<DataType>::size() const
{
    return elementCount;
    //to get the size just return element count
}

template <class DataType>
void miniQueueDA<DataType>::PrintQueue() const
{
    for(int i = 0; i < elementCount; i++)
    {
        cout << content[i] << " ";
    }
}

template <class DataType>
void miniQueueDA<DataType>::dequeue()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue dequeue is empty");
    }
    elementCount --;
    DataType *temp = new DataType[elementCount];
    //subtract element and create new data type when adding to queue
    for(int i = 0; i< elementCount; i++)
    {
        temp[i] = content[i+1];
    }
    delete []content;
    content = temp;
    //delete the content and reassign it to temp
}

template <class DataType>
void miniQueueDA<DataType>::enqueue(const DataType & c)
{
    //change this one
    elementCount ++;
    DataType *temp = new DataType[elementCount];
    //increase element count and create new datatype
    for(int i = 0; i < elementCount; i++)
    {
        if(i==elementCount-1)
        {
            temp[i] = c;
        }
        else
        {
            temp[i] = content[i];
        }
    }
    delete []content;
    content = temp;
    //delete content and reassign it to temp
}
template <class DataType>
DataType& miniQueueDA<DataType>::front()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue front is empty");
    }
    return content[0];
    //return first element of content array
}
template <class DataType>
const DataType& miniQueueDA<DataType>::front()const
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue front is empty");
    }
    return content[0];
    //return first element of content array
}

