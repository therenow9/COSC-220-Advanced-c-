#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include "t_node.h"
#include "functions.h"
using namespace std;
//linked list node

template <typename T>
class BSTree
{
private:
    Tnode<T> *root;
    void insert(Tnode<T>* &r,const T & item);
    void Delete(Tnode<T>* &r,const T & item);
public:
    //declaration
    BSTree():root(NULL){};
    //make root = null
    Tnode<T>*getRoot();
    ~BSTree();
    void BSTInsert (const T & item);
    void BSTDelete (const T & item);
};
#include "BSTree.cpp"
#endif // NODE
