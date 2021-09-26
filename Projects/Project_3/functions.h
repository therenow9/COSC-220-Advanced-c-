#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void readmaze(char maze[][6],string mazeno);

void print2dArray(char maze[][6]);

bool findPath (int row, int col, char maze[][6],int start_x,int start_y);

void findStart(char maze[][6],int &start_x, int &start_y);
#include "functions.cpp"
#endif // FUNCTIONS




