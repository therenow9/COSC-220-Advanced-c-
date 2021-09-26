#include <iostream>
using namespace std;

class Node{
public:
int value;
Node *next;
Node(){value = 0; next=NULL;}
};

// print out the value in a linked list
void PrintList(Node* list, string & separator );
void PrintList(Node* list, string & separator )
{
    separator="  ";
    cout<<"List of Nodes:"<<endl;
        Node* curr = NULL;
        curr->value=1;
    while(curr!= NULL)
    {
        cout << curr->value << separator;
        curr = curr->next;
        //reassign
    }
    cout<<endl;
}
void buildList(Node* &list, int n);
void buildList(Node* &list, int n){
    Node*curr=list;


  for (int i=0; i<n;i++){
        curr->value=1;
curr=curr->next;

list=curr;
  }

}
int main()
{
Node *curr;
curr->value=1;
string sep="  ";
PrintList(curr,sep);



    return 0;
}
