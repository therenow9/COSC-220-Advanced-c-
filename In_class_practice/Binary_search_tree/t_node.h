#ifndef NODE_CLASS
#define NODE_CLASS

#ifndef NULL
#include <cstddef
#endif // NULL

//linked list node

template <typename T>
class node{

public:
    T nodeValue;
    //data held by node
    node <T> *parent;
    node <T> *left;
    node <T> *right;
    //next node in list
    Tnode():nodeValue(0),parent(NULL),left(NULL),right(NULL){}
}    //default constructor
    node():next(NULL){}

    //constructor init node value
    node (const T& item,node <T>,*nextNode=NULL):nodeValue(item),next(nextNode)
    {}
};

#endif // NODE_CLASS
