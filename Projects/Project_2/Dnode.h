#ifndef DNODE

#define DNODE // DNODE

#include <iostream>
template <typename T>
class Dnode
{
public:
    T value;
//value to be stored
    Dnode<T>*prev;
    Dnode<T>*next;
//declare prev and next to access them in list
    Dnode():next(NULL),prev(NULL) {};
    Dnode(const T& item, Dnode* nextNode = NULL, Dnode* prevNode = NULL):value(item), next(nextNode), prev(prevNode) {};

};
#endif // DNODE
