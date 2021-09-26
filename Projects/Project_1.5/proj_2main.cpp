//Jeremy  Scheuerman
//COSC 220

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "proj_2_db_functions.h"
#include "proj_2_aux_functions.h"
#include "proj_2_employee.h"
#include "Link.h"

using namespace std;

int main()
{
    int eCount;
    node<Employee>* head;
    //open employee database file
    readDatabase(head,eCount);
    printDatabase(head,eCount);
    displayMenu(head,eCount);
    return 0;
}
