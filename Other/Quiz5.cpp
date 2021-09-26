#include <iostream>

class Node{
public:
int value;
Node *next;
Node(){value = 0; next=NULL;}
};

// print out the value in a linked list

void printList(Node* list){
    Node* curr = list;
    while(curr != NULL)
    {
        std::cout << curr->value << " ";
        curr = curr->next;
        //print value while not done
    }


}

// Create in a linked list with n Node objects and ask user to enter the value for each Node object.

void buildList(Node* &list, int n){
    Node*curr= list;
    int v;
    if (n==0)
    {
        std::cout << "empty list" << std::endl;
        //not creating anythin
        return;
    }
    else
    {
        for(int i = n; i > 0; i--)
        {
            std::cout << "Please enter the " << i << " value" << std::endl;
            std::cin >> v;
            //getting value
            list = new Node;
            //adding a new node onto the list
            list->value = v;
            //setting it equal to v
            list->next = curr;
            //setting next element after to curr
            curr = list;
            //set curr = to whole linked list

        }
    }
}

int main(){
Node * list = NULL;
// ask user to enter an integer and read it in
int n;
std::cout << "Please enter in a integer" << std::endl;
std::cin >>n;

// call function void buildList(Node* &list, int n) to build a list of length read in above
buildList(list, n);

// call function void printList(Node* list) to print the list
printList(list);


return 0;
}
