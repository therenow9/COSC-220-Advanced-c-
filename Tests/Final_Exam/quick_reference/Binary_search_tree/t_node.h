#ifndef NODE_CLASS
#define NODE_CLASS
#include <iostream>

//linked list node
using namespace std;
template <typename T>
class Tnode{

public:
    T nodeValue;
    //data held by node
    Tnode <T> *parent;
    Tnode <T> *left;
    Tnode <T> *right;
    //next node in list
    Tnode():nodeValue(0),parent(NULL),left(NULL),right(NULL){};
    void PrintNodeInfo();

 //default constructor

    //constructor init node value
    Tnode (const T& item,Tnode <T>*parentNode=NULL,Tnode <T>*leftNode=NULL,Tnode <T>*rightNode=NULL);
};
#include "t_node.cpp"
#endif // NODE_CLASS
