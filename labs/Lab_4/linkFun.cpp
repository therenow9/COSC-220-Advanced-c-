//Jeremy Scheuerman
//lab 4
//Dr. Wang
#include "Link.h"
#include <iostream>
using namespace std;

//define functions
template <typename T>
node<T>* CreateNode(const T &value);

template <typename T>
void InsertNode(node<T>* &front, const T & value );

template <typename T>
node<T>* SearchNode(node<T>* front, const T & value);

template <typename T>
void DeleteNode(node<T>* &front, const T & value);

template <typename T>
void Printlist(node<T>* front,const string &seperator =" ");

template <typename T>
node<T>* CreateNode(const T &value)
{
    node<T>* Node = new node<T>(value, NULL);
    return Node;
}

template <typename T>
void InsertNode(node<T>* &front, const T & value )
{
    node<T>* curr = NULL;
    node<T>* prev = NULL;
    curr = front;

    if(curr == NULL)
        //if at end of list/ non existent value
    {
        prev = new node<T>(value, curr);
        front = prev;
    }
    else
    {
        while(curr != NULL)
            //while not at end of the list
        {
            if (curr == front)
            {
                if(curr->nodeValue > value)
                {
                    prev = new node<T>(value, curr);
                    front = prev;
                    break;
                }
                else if (curr->next == NULL)
                {
                    if(curr->nodeValue < value)
                    {
                        node<T>* insNode = new node<T>(value, curr->next);
                        curr->next = insNode;
                        break;
                    }
                }
            }
            else
            {
                if(curr->nodeValue > value)
                    //sort so nodes are in order
                {
                    node<T>* insNode = new node<T>(value, prev->next);
                    prev->next = insNode;
                    break;
                }
                else if (curr->next == NULL)
                {
                    node<T>* insNode = new node<T>(value, curr->next);
                    curr->next = insNode;
                    break;
                }
            }
            prev = curr;
            curr = curr->next;
            //update assignments
        }
    }
}

template <typename T>
node<T>* SearchNode(node<T>* front, const T & value)
{
    node<T>* curr = NULL;
    curr = front;

    while(curr != NULL)
    {
        if(curr->nodeValue == value)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

template <typename T>
void DeleteNode(node<T>* &front, const T & value)
{
    node<T>* curr = NULL;
    node<T>* prev = NULL;
    curr = front;
    //do assignments

    while(curr!= NULL)
    {
        if(curr == front)
            //if at top
        {
            if(curr->nodeValue == value)
                //do deletion
            {
                front = curr->next;
                delete curr;
                return;
            }
        }
        else
            //not at the top
        {
            if(curr->nodeValue == value)
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
        }
        prev = curr;
        curr = curr->next;
        //do reassign
    }
}

template <typename T>
void PrintList(node<T>* front, const string & separator = " ")
{
    cout<<"List of Nodes:"<<endl;
        node<T>* curr = front;
    while(curr!= NULL)
    {
        cout << curr->nodeValue << separator;
        curr = curr->next;
        //reassign
    }
    cout<<endl;
}
