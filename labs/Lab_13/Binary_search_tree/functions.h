#ifndef FUNCTIONS
#define FUNCTIONS
#include <iostream>
#include "BSTree.h"
using namespace std;
//define functions
template <typename T>
void InOrder (Tnode<T> *r);
template <typename T>
void PreOrder (Tnode<T> *r);
template <typename T>
void PostOrder (Tnode<T> *r);
template <typename T>
Tnode<T> * Search (Tnode<T> *r, const T &item);
template <typename T>
Tnode<T> * SearchMax (Tnode<T> *r);
template <typename T>
Tnode<T> * SearchMin (Tnode<T> *r);
template <typename T>
int countLeaves (Tnode<T> *  r);
template <typename T>
Tnode<T> * Tree_succesor(Tnode<T> *r);
template <typename T>
void menu(Tnode <T> bt);

#include "functions.cpp"
#endif







