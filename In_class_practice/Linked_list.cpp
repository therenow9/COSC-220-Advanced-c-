//Jeremy Scheuerman
//In Class Practice
//Linked list
#using namespace std;

void insertAtheadLinkedList(Node * &hd,int value)
//head - new node(i,head);
class Node
{
public:
    int value;
    Node *next;
    Node()value
    {
        value=1;
        next=nullptr;
    }
    Node(int v,Node *new_Node)
    {
        value=v;
        next=new_Node;
    }
};

int main()
{

    for (int i=100; i>0; i--)
    {

        head=new Node(i,head);

    }
    Node * curr=head;
    while  (curr!=nullptr)
    {

        cout<<curr->value<<"_";
        curr-curr->next;
    }
}
