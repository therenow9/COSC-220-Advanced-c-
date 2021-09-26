#ifndef DB
#define DB

#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_1_employee.h"
#include "proj_1_aux_functions.h"
using namespace std;

void readDatabase(Employee* &eList,int &eCount);
void writeDatabase(Employee* &eList,int &eCount);
void retrieveEmployee(Employee* eList, int &eCount);
bool deleteEmployee(Employee*&eList, int &eCount);
bool modifyEmployee(Employee* &eList,int &eCount);
bool insertEmployee(Employee* &eList,int &eCount);
void printDatabase(Employee*& eList, int &eCount);
void printEmployee(Employee Joe);
void displayMenu(Employee* eList,int &eCount);
//declare functions

#endif

