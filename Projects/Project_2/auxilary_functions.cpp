#include <iostream>
//#include "auxilary_functions.h"
int get_actions()
{
    //menu for choosing the
    int action =-1;
    while (action<1||action>5)
    {
        cout<<"Choose one of the following actions"<<endl
            <<"1: add element"<<endl<<"2: Remove element"<<endl
            <<"3: Print"<<endl<<"4: Print top element"<<endl
            <<"5: to exit"<<endl;
        cin>>action;
    }
    cout<<endl;
    return action;
}
int get_choice()
{
    int choice=-1;
    while(choice<1||choice>2)
        //validate input
    {
        if(cin.fail())
        {
            cout<<"Invalid Choice"<<endl;
        }
        cout<<"Enter 1 for Stack or 2 for Queue"<<endl;
        cin>>choice;
    }
    return choice;
}
int get_implementation()
{
    int impl=-1;
    //choose which implemenation you would like to work with
    while (impl<1||impl>4)
    {
        cout<<"Choose the implementation you would like to use"<<endl<<
            "1: Vector"<<endl<<"2: Dynamic Array"<<endl<<"3: List"<<endl<<"4: Doubly Linked List"<<endl;
        cin>>impl;
    }
    cout<<endl;
    return impl;
}
template <class DataType>
void addElement   ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                    miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl)
//add element for stack
{
    /*
    for the implementation
        1=vt 2=da 3=lt 4=dl;
        */
    int value = -1;
    do
    {
        //error check
        if(cin.fail())
        {
            cout << "Invalid value" << endl << endl;
        }
        cout << "Please enter a value to add to the stack" << endl;
        cin >> value;
    }
    while(cin.fail());


    switch (impl)
        //implementation depending on which impl was chosen
    {
    case 1:
        stack_vt.Push(value);
        break;
    case 2:
        stack_da.Push(value);
        break;
    case 3:
        stack_lt.Push(value);
        break;
    case 4:
        stack_dl.Push (value);
        break;
    }
}
//add element overload for stacks
template <class DataType>
void addElement   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl)
//add element overload for queue
{
//add element for queue
    /*
    for the implementation
        1=vt 2=da 3=lt 4=dl;
        */
    int value = -1;
    do
    {
        //error check
        if(cin.fail())
        {
            cout << "Invalid value" << endl << endl;
        }
        cout << "Please enter a value to add to the queue" << endl;
        cin >> value;
    }
    while(cin.fail());

    switch (impl)
        //implementation depending on which impl was chosen
    {
    case 1:
        queue_vt.enqueue(value);
        break;
    case 2:
        queue_da.enqueue(value);
        break;
    case 3:
        queue_lt.enqueue(value);
        break;
    case 4:
        queue_dl.enqueue (value);
        break;
    }

}
template <class DataType>
void deleteElement   ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                       miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl)
//delete element for stack
{
    /*
    for the implementation
        1=vt 2=da 3=lt 4=dl;
        */


    try
    {
        switch (impl)
            //implementation depending on which impl was chosen
        {
        case 1:
            stack_vt.Pop();
            break;
        case 2:
            stack_da.Pop();
            break;
        case 3:
            stack_lt.Pop();
            break;
        case 4:
            stack_dl.Pop();
            break;
        }
    }
    catch(baseException& e)
        //add exceptino handling
    {
        cout<<e.what()<<endl;
    }
}
template <class DataType>
void deleteElement   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                         miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl)
//delete element from queue
{
    /*
    for the implementation
        1=vt 2=da 3=lt 4=dl;
        */
    try
    {
        switch (impl)
            //implementation depending on which impl was chosen
        {
        case 1:
            queue_vt.dequeue();
            break;
        case 2:
            queue_da.dequeue();
            break;
        case 3:
            queue_lt.dequeue();
            break;
        case 4:
            queue_dl.dequeue();
            break;
        }
    }
    catch(baseException& e)
        //add exception handling
    {
        cout<<e.what()<<endl;
    }
}
template <class DataType>
void printElement( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                       miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl)
{
    /*
       for the implementation
           1=vt 2=da 3=lt 4=dl;
           */

    switch (impl)
    {
    case 1:
        if(stack_vt.IsEmpty())
            cout << "The stack (VT) is empty" << endl;
        //print empty to avoid error
        else
        {
            //if not print the stack
            cout << "Stack (VT): ";
            stack_vt.PrintStack();
            cout << endl;
        }
        break;
    case 2:
        if(stack_da.IsEmpty())
            cout << "The stack (DA) is empty" << endl;
        else
        {
            cout << "Stack(DA): ";
            stack_da.PrintStack();
            cout << endl;
        }
        break;
    case 3:
        if(stack_lt.IsEmpty())
            cout << "The stack (LT) is empty" << endl;
        else
        {
            cout << "Stack(LT): ";
            stack_lt.PrintStack();
            cout << endl;
        }
        break;
    case 4:
        if(stack_dl.IsEmpty())
            cout << "The stack is empty" << endl;
        else
        {
            cout << "Stack(DL): ";
            stack_dl.PrintStack();
            cout << endl;
        }
        break;
    }
}
template <class DataType>
void printElement   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                        miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl)
//Print element overload for queue
{
    /*
       for the implementation
           1=vt 2=da 3=lt 4=dl;
           */

    switch (impl)
    {
    case 1:
        if(queue_vt.IsEmpty())
            cout << "The queue (VT) is empty" << endl;
        //print empty to avoid error
        else
        {
            //if not print the queue
            cout << "Queue (VT): ";
            queue_vt.PrintQueue();
            cout << endl;
        }
        break;
    case 2:
        if(queue_da.IsEmpty())
            cout << "The queue (DA) is empty" << endl;
        else
        {
            cout << "Queue (DA): ";
            queue_da.PrintQueue();
            cout << endl;
        }
        break;
    case 3:
        if(queue_lt.IsEmpty())
            cout << "The queue (LT) is empty" << endl;
        else
        {
            cout << "Queue(LT): ";
            queue_lt.PrintQueue();
            cout << endl;
        }
        break;
    case 4:
        if(queue_dl.IsEmpty())
            cout << "The queue (DL) is empty" << endl;
        else
        {
            cout << "Queue(DL): ";
            queue_dl.PrintQueue();
            cout << endl;
        }
        break;
    }
}
template <class DataType>
void printTop  ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                 miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl)
//Print top for stack
{
    /*
    for the implementation
       1=vt 2=da 3=lt 4=dl;
       */
    try
    {
        switch(impl)
        {
        case 1:
            cout<<"Top (VT):"<<stack_vt.TopStack()<<endl;
            break;
        case 2:
            cout<<"Top (DA):"<<stack_da.TopStack()<<endl;
            break;
        case 3:
            cout<<"Top (LT):"<<stack_lt.TopStack()<<endl;
            break;
        case 4:
            cout<<"Top (DL):"<<stack_dl.TopStack()<<endl;
            break;
        }

    }
    catch(baseException &e)
    {
        cout<<e.what()<<endl;
        //print exception
    }
}
template <class DataType>
void printFront   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl)
//Print top for stack
{
    /*
    for the implementation
       1=vt 2=da 3=lt 4=dl;
       */
    try
    {
        switch(impl)
        {
        case 1:
            cout<<"Front (VT):"<<queue_vt.front()<<endl;
            break;
        case 2:
            cout<<"Front (DA):"<<queue_da.front()<<endl;
            break;
        case 3:
            cout<<"Front (LT):"<<queue_lt.front()<<endl;
            break;
        case 4:
            cout<<"Front (DL):"<<queue_dl.front()<<endl;
            break;
        }

    }
    catch(baseException &e)
    {
        cout<<e.what()<<endl;
        //print exception
    }
}
template <class DataType>
void execute(int choice, int impl, int act,
             //stack or queue, which implementation, and which action
             miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
             miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,
             miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
             miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl)
{
    /* case statement guide
    1(choice)=stack
    2(choice)=queue
    1=add
    2=remove
    3=print
    4=print (Front/top)
    5=exit
    */
    if (act==5)
    {
        return;
    }
    else if(choice==1)
        //stack
    {
        switch (act)
        {
        case 1://add element
            addElement(stack_vt,stack_da,stack_lt,stack_dl,impl);
            break;
        case 2://delete element
            deleteElement(stack_vt,stack_da,stack_lt,stack_dl,impl);
            break;
        case 3://print element
            printElement(stack_vt,stack_da,stack_lt,stack_dl,impl);
            break;
        case 4://print top
            printTop(stack_vt,stack_da,stack_lt,stack_dl,impl);
            break;
        }

    }
    else if(choice==2)
        //queue
    {
        switch (act)
        {
        case 1://add element
            addElement(queue_vt,queue_da,queue_lt,queue_dl,impl);
            break;
        case 2://delete element
            deleteElement(queue_vt,queue_da,queue_lt,queue_dl,impl);
            break;
        case 3://print element
            printElement(queue_vt,queue_da,queue_lt,queue_dl,impl);
            break;
        case 4://print front
            printFront(queue_vt,queue_da,queue_lt,queue_dl,impl);
            break;
        }

    }
    cout<<endl;
}
