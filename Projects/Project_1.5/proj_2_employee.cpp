#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_2_employee.h"
#include <string>
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
string Employee::getFirstName()const
{
    return firstName;
}
string Employee::getLastName()const
{
    return lastName;
}
string Employee::getSSN()const
{
    return ssn;
}
int Employee::getSSN_NoDash()const
{
    //get ssn without dashes in it
    string nodash=ssn.substr(0,3)+ssn.substr(4,2)+ssn.substr(7,5);
    int no_dash=stoi(nodash);
    return no_dash;
}
string Employee::getBirthDate()const
{
    return birthday;
}
double Employee::getSalary()const
{
    return salary;
}
bool Employee::operator>(Employee Joe)
{
    if(ssn.compare(Joe.getSSN()) > 0)
        return true;
    return false;
}

bool Employee::operator<(Employee Joe)
{
    if(ssn.compare(Joe.getSSN()) < 0)
        return true;
    return false;
}
bool Employee::operator==(Employee Joe)
{
    if(ssn.compare(Joe.getSSN()) == 0)
        return true;
    return false;
}
ostream &operator<< (ostream &output,Employee &Joe)
{
    //overload the print operator

    output <<setw(10)<< Joe.getFirstName()<<setw(13)<<
           Joe.getLastName()<<setw(13)<<Joe.getSSN()
           <<setw(11)<<Joe.getBirthDate()<<setw(10)<<
           Joe.getSalary()<<endl;
    return output;

}

istream &operator>> (istream &input,Employee &emp)
{
    string name_first, name_last, ssn, bday;
    int salary;

    input >> name_first >> name_last >> ssn >> bday >> salary;
    //get input
    emp.setFirstName(name_first);
    emp.setLastName(name_last);
    emp.setSSN(ssn);
    emp.setBirthDate(bday);
    emp.setSalary(salary);

    return input;
}



