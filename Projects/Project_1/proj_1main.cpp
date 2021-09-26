//Jeremy  Scheuerman
//COSC 220

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "proj_1_aux_functions.h"
#include "proj_1_db_functions.h"
#include "proj_1_employee.h"

using namespace std;

int main()
{   int eCount;
    Employee *emp_list;
    //open employee database file
    readDatabase(emp_list,eCount);
    printDatabase(emp_list,eCount);
    displayMenu(emp_list,eCount);
    return 0;
}
