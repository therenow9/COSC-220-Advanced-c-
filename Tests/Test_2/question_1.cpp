#include <iostream>
#include <list>

using namespace std;

template <typename T>
class node
{
public:
    T nodeValue;
    node<T>*next;
    node():nodeValue(T()), next(NULL) { }
    // default constructor to set nodeValue to be zero and set next to be NULL
    node(const T& item, node *nextNode=NULL): nodeValue(item),next(nextNode) { }
    // constructor to set nodeValue to be newValue and set next to nextNode
};
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
            if((curr->nodeValue).getSSN() == value.getSSN())
                //do deletion
            {
                front = curr->next;
                delete curr;
                break;
            }
        }
        else
            //not at the top
        {
            if((curr->nodeValue).getSSN() == value.getSSN())
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
        }
        prev = curr;
        curr = curr->nextNode;
        //do reassign
    }
}

class professor
{
public:
    //classes list set at 0
    string name;
    int class_amnt;
    list<string>classes(class_amnt);
    list<int>::iterator iter;
    iter=classes.begin();

    professor();

};

int main()
{
    node <professor>* head;
    int choice;
    int prof_count=0;
    while (choice!=6)
        cout<<"1 Display Professors"<<endl<<"2 insert professor"
            <<endl<<"3 delete professor"<<endl<<"4 Modify professor"<<endl;
    choice=-1;
    while (choice<0||choice>4)
        //error check
    {
        cout<<"Enter your selection:"<<endl;
        cin>>choice;
    }
    switch (choice)
    {
    case 1:
        break;
    case 2:
    {
        professor temp;
        cout<<"Enter the professors name"<<endl;
        cin>>temp.name;
        cout<<"Enter the amount of classes the professor teaches"<<endl;
        cin>>temp.class_amnt;
        prof_count+=1;
        /*
        for (int i=0;i<temp.class_amnt){
               string temp_class;
            cout<<"Enter class "<<i<<endl;
            cin>>temp_class;
            *iter=temp_class;
            iter++;

        }
        */
        InsertNode(head,temp);
    }
    break;
    case 3:
    {

        string temp_del;
        cout<<"Please enter the name of the professor you would like to delete"<<endl;
        cin>>temp_del;
        node <professor>*curr=head;
        for(int i=0; i<prof_count; i++)
        {
            if(curr->nodeValue.name==temp_del)
            {
                DeleteNode(head,curr);
                return;
            }
            else
            {
                curr=curr->next;
            }

        }
    }
    break;
    case 4:
    {
        string temp_prof
        cout<<"Enter the name of the professor you would like to modify "<<endl;
        cin>>temp_prof;
        cout<<"Would you like to insert or delete a class (1 for insert to for delete)"<<endl;
        int choice;
        cin>>choice;


        node <professor>*curr=head;
        for(int i=0; i<prof_count; i++)
        {
            if(curr->nodeValue.name==temp_prof)
            {
                DeleteNode(head,curr);
                return;
            }
            else
            {
                curr=curr->next;
            }

        }
    }

    break;
    case 5:
        cout<<"Exiting program"<<endl;
        return 0;
        break;
    }
}

