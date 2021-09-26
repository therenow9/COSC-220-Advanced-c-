//Jeremy Scheuerman
//Lab 4
//Dr.Wang

#ifndef LINK_H
#define LINK_H

#include <iostream>
template <typename T>

class node
{
public:
    T nodeValue;
    node<T>*next;
    node():nodeValue(0), next(NULL) { }
    // default constructor to set nodeValue to be zero and set next to be NULL
    node(const T& item, node *nextNode=NULL): nodeValue(item),next(nextNode) { }
     // constructor to set nodeValue to be newValue and set next to nextNode
};
#endif
