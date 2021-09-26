#include <iostream>

using namespace std;

class node{
public:
    int value;
    Node* next;
    Node(){
    value=0;
    next=null;
    }
    Node(int v,Node *newNode){
    value =v;
    next=newNode;
    }


};
