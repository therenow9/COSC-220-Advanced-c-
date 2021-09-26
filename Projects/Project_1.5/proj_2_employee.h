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
    string getFirstName()const;
    string getLastName()const;
    string getSSN()const;
    int getSSN_NoDash()const;
    string getBirthDate()const;
    double getSalary()const;
    //note but const for getters
    void setFirstName(string fn);
    void setLastName(string ln);
    void setSSN(string s);
    void setBirthDate(string bd);
    void setSalary(double sal);
    bool operator<(Employee Joe);
    bool operator>(Employee Joe);
    bool operator==(Employee Joe);
    friend ostream &operator<< (ostream &output,Employee &Joe);
    friend istream &operator>> (istream &input,Employee &emp);

    //overload these operator

};

#include "proj_2_employee.cpp"
#endif

