#include "miniStackDL.h"
template <class DataType>
miniStackDL<DataType>::miniStackDL()
{
    head=NULL;
    //init as null or else error
    elementCount = 0;
    //set element count to 0
}
template <class DataType>
int miniStackDL<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniStackDL<DataType>::IsEmpty() const
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
miniStackDL<DataType>::~miniStackDL()
{
    Dnode <DataType>*temp=head;
    while (head!=NULL){
    head=head->next;
    delete temp;
    temp=head;
    }
}

template <class DataType>
void miniStackDL<DataType>::Push (const DataType & c)
{
   head=new Dnode<DataType>(c,head);
    if (head->next!=NULL){
    head->next->prev=head;
    }
       elementCount ++;
       //update amount of elements
}

template <class DataType>
void miniStackDL<DataType>::PrintStack () const
{
    Dnode <DataType>*temp=head;
    while (temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
    //Declare list and print out each value
}


template <class DataType>
void miniStackDL<DataType>::Pop()
{
      if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    Dnode <DataType>*temp=head;
    head=head->next;
    delete temp;
    elementCount --;

    //subtract from element count and pop out the front
}

template <class DataType>
DataType& miniStackDL<DataType>::TopStack()
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return head->value;
    //return first element of content array
}
template <class DataType>
const DataType& miniStackDL<DataType>::TopStack() const
{
    if (elementCount==0)
    {
        throw underflowError("miniStack top is empty");
    }
    return head->value;
    //return first element of content array
}
