#ifndef AUXILARY_FUNCTIONS_H
#define AUXILARY_FUNCTIONS_H

#include "miniStackDA.h"
#include "miniStackDL.h"
#include "miniStackLT.h"
#include "miniStackVT.h"
#include "miniQueueDA.h"
#include "miniQueueVT.h"
#include "miniQueueDL.h"
#include "miniQueueLT.h"
#include <iostream>

using namespace std;

int get_actions();
//choose type you would like to use
int get_choice();
//get stack or queue
int get_implementation();
template <class DataType>
void addElement   ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                    miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl);
//add element overload for stacks
template <class DataType>
void addElement   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl);
//add element overload for queue
template <class DataType>
void deleteElement   ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                       miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl);
//delete element overload for queue
template <class DataType>
void deleteElement   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl);
//add element overload for queue
template <class DataType>
void printElement  ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                       miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl);
//Print element overload for stack
template <class DataType>
void printElement (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl);
//Print element overload for queue
template <class DataType>
void printTop  ( miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
                       miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,int impl);
//Print top for stack
template <class DataType>
void printFront   (   miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
                      miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl,int impl);
//Print front for queue
template <class DataType>
void execute(int sq, int o, int i,
             miniStackVT<DataType>& stack_vt, miniStackDA<DataType>& stack_da,
             miniStackLT<DataType>& stack_lt, miniStackDL<DataType>& stack_dl,
             miniQueueVT<DataType>& queue_vt, miniQueueDA<DataType>& queue_da,
             miniQueueLT<DataType>& queue_lt, miniQueueDL<DataType>& queue_dl);
             //do the execution
#include "auxilary_functions.cpp"
#endif // AUXILARY_FUNCTIONS
