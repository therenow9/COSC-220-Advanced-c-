#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_1_employee.h"
using namespace std;

Employee::Employee()
{
//empty declaration
}
Employee::Employee(string fn,string ln,string ssn,double sal)
{
    fn="John";
    ln="Doe";
    ssn="123-45-6789";
    sal=100000;
}
void Employee::setFirstName(string fn)
{
    firstName = fn;
}
void Employee::setLastName(string ln)
{
    lastName = ln;
}
void Employee::setSSN(string s)
{
    ssn = s;
}
void Employee::setBirthDate(string bd)
{
    birthday = bd;
}
void Employee::setSalary(double sal)
{
    salary = sal;
}
//setter functions defined
string Employee::getFirstName()
{
    return firstName;
}
string Employee::getLastName()
{
    return lastName;
}
string Employee::getSSN()
{
    return ssn;
}
string Employee::getBirthDate()
{
    return birthday;
}
double Employee::getSalary()
{
    return salary;
}

