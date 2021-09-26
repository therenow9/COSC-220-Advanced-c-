#include "miniQueueDL.h"

template <class DataType>
miniQueueDL<DataType>::miniQueueDL()
{
    head=NULL;
    //init as null or else error
    elementCount = 0;
    //set element count to 0
}
template <class DataType>
int miniQueueDL<DataType>::size() const
{
    return elementCount;
}

template <class DataType>
bool miniQueueDL<DataType>::IsEmpty() const
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
miniQueueDL<DataType>::~miniQueueDL()
{
    Dnode <DataType>*temp=head;
    while (head!=NULL)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
}

template <class DataType>
void miniQueueDL<DataType>::enqueue (const DataType & c)
{
    Dnode <DataType>*temp=head;
    Dnode<DataType>*insertNode=new Dnode<DataType>(c);
    if (head==NULL){
        head=insertNode;
        //update head assignment
    }else{
    while (temp->next!=NULL)
    {
        //stop right before NULL element
        temp=temp->next;
    }
    temp->next=insertNode;
    insertNode->prev=temp;
    //update assignment
    }
    elementCount ++;
    //update amount of elements
}

template <class DataType>
void miniQueueDL<DataType>::PrintQueue () const
{
    Dnode <DataType>*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
    //Declare list and print out each value
}


template <class DataType>
void miniQueueDL<DataType>::dequeue()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue top is empty");
    }
    Dnode <DataType>*temp=head;
    head=head->next;
    delete temp;
    elementCount --;

    //subtract from element count and pop out the front
}

template <class DataType>
DataType& miniQueueDL<DataType>::front()
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue top is empty");
    }
    return head->value;
    //return first element of content array
}
template <class DataType>
const DataType& miniQueueDL<DataType>::front() const
{
    if (elementCount==0)
    {
        throw underflowError("miniQueue top is empty");
    }
    return head->value;
    //return first element of content array
}
