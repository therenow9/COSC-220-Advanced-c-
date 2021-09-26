#ifndef DB
#define DB

#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_2_employee.h"
#include "proj_2_aux_functions.h"
#include "link.h"
using namespace std;
template <typename T>
void readDatabase(node<T>* &eList,int &eCount);

template <typename T>
void writeDatabase(node<T>* &eList,int &eCount);

template <typename T>
void retrieveEmployee(node<T>* &eList, int &eCount);

template <typename T>
bool deleteEmployee(node<T>* &eList, int &eCount);

template <typename T>
bool modifyEmployee(node<T>* &eList,int &eCount);

template <typename T>
bool insertEmployee(node<T>* &eList,int &eCount);

template <typename T>
void printDatabase(node<T>* eList, int &eCount);

void printEmployee(Employee Joe);

template <typename T>
void displayMenu(node<T>* &eList,int &eCount);

template <typename T>
void sortDatabase(node<T> *head,int eCount,int choice=1,bool display=false);

//declare functions
template <typename T>
void SSN_sort(node<T>* &head,int &eCount);

#include "proj_2_db_functions.cpp"
#endif

