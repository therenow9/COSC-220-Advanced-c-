#ifndef EMP
#define EMP
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Employee
{
private:
    string firstName;
    string lastName;
    string ssn;
    string birthday;
    double salary;

public:
    //define constructors
    Employee();
    Employee(string fn, string ln, string ssn, double sal);
    //define getter/setter for firstName,lastName,salary
    string getFirstName();
    string getLastName();
    string getSSN();
    string getBirthDate();
    double getSalary();
    void setFirstName(string fn);
    void setLastName(string ln);
    void setSSN(string s);
    void setBirthDate(string bd);
    void setSalary(double sal);
};



#endif