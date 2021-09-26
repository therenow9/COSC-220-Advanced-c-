//Jeremy Scheuerman
//lab 4
//Dr.Wang

#include "linkFun.cpp"
#include "link.h"
#include <iostream>

using namespace std;

int display_Menu();
bool Validate_Menu(int choice);
template<typename T>
bool Validate_Node(T Node );
template<typename T>
void Menu_Selection(node<T>* &front, int selection);


int main()
{
    int choice;
    node<int> *front=nullptr;
    while (true)
        //user has not made a choice
    {
        choice=display_Menu();
        //get user choice
        Menu_Selection(front,choice);
    }
    cout<<"Exiting"<<endl;
    return 0;
}


int display_Menu()
{
    int choice=-1;
    bool done=false;
    do
    {
        cout<<"Here are the options for manipulating the linked list"<<endl<<
            "Choose one of the following (1-5)"<<endl;
        cout<<"1 -Insert Node"<<endl<<"2 -Delete node"<<
            endl<<"3 -Print list of Nodes"<<endl<<
            "4 -Search and Retrieve Node"<<endl<<
            "5 -Exit"<<endl;
        //display options
        cin>>choice;
        done=Validate_Menu(choice);
    }
    while (done==false);
    return choice;
}
template<typename T>
void Menu_Selection(node<T>* &front, int choice)
{
    bool valid=false;
    T input;
    //declare
    switch(choice)
    {
    case 1:

        //insert node
        valid=false;
        while(valid==false)
        {
            cout<<"Enter a value to insert"<<endl;
            cin>>input;
            cout<<endl;
            valid=Validate_Node(input);
        }
        InsertNode(front,input);
        break;

    case 2:

        //delete node
        valid=false;
        cout<<"Enter a value to delete"<<endl;
        cin>>input;
        cout<<endl;
        DeleteNode(front,input);
        break;
    case 3:

        PrintList(front);
//print
        break;

    case 4:

        //search node
        valid=false;
        cout<<"Enter a value to search for"<<endl;
        cin>>input;
        cout<<endl;
        node<T>* curr=SearchNode(front,input);
        //search through the linked list
        if (curr!=nullptr)
        {
            cout<<curr->nodeValue;
            cout<<endl;
        }
        else
        {
            cout<<"Specified value does not exist"<<endl;
        }
        break;
    }
}

bool Validate_Menu(int choice)
{
    bool valid=true;
    if (cin.fail()||choice>5||choice<1)
    {
        cin.clear();
        cin.ignore(9999,'\n');
        cout<<"Invalid input try again (1-5)"<<endl<<endl;
        //validate the input
        valid=false;
    }
    return valid;
    //return if input is valid
}
template <typename T>
bool Validate_Node(T value)
{
    bool valid=true;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999,'\n');
        cout << "Invalid Input try again" << endl << endl;
        //do validation
        valid=false;
    }
    valid=true;
    return valid;
}
