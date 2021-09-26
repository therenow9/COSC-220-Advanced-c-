
#include <iostream>
#include <cstdlib>


using namespace std;
void deleteSecond()
//delete second to last element of a linked list
{
    if (head==NULL)
    {

        return
    }
    if (head->next==NULL){

        return;
    }
    Node* curr=head;
    Node* p=curr->next;
    Node* q=p->next;
    //manipulate curr
    while(q->next!=NULL){

        curr=curr->next;
        p=p->next;
        q=q->next;
    }
    curr->next=q;


}
struct node
//create node class
{
    int data;
    node* next;
    node* prev;
    //pointers to access previous and next node

};

int main()
{
    node *head;
//create head node
    node *curr

    return 0;
}
