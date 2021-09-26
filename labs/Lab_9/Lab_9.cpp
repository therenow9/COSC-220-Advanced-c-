#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include "Lab_9.h"
using namespace std;
Employee::Employee(string fn,string ln,string title,double sal)
{
    //implement constructor setters with default values
    setFirstName(fn);
    setLastName(ln);
    setJobTitle(title);
    setBaseSalary(sal);
}
void Employee::setFirstName(string fn)
{
    firstName = fn;
}
void Employee::setLastName(string ln)
{
    lastName = ln;
}
void Employee::setJobTitle(string t)
{
    title = t;
}

void Employee::setBaseSalary(double sal)
{
    baseSalary = sal;
}
double Employee::CalculateSalary()
{
    return baseSalary;
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
string Employee::getJobTitle()const
{
    return title;
}
double Employee::getBaseSalary()const
{
    return baseSalary;
}
//member functions
void Employee::displayJobTitle()
{
    cout<<title;
}
void Employee::displayBaseSalary()
{
    cout<<baseSalary;
}
void Employee::displayInfo()
{
    cout<<"Info"<<endl<<"First:"<<getFirstName()<<endl<<"Last:"<<getLastName()<<endl
        <<"Title:"<<getJobTitle()<<endl<<"Salary:"<<getBaseSalary()<<endl<<endl;
    //display employee info
}

//Functions for Manager
Manager::Manager(string fn,string ln,string title,double sal,double b):Employee(fn,ln,title,sal)
{
    setBonus(b);
    //call derived constructor after initial cosntructor
}
double Manager::getBonus()const
{
    return bonus;
}
void Manager::setBonus(double b)
{
    bonus=b;
}
void Manager::displayBonus()
{
    cout<<bonus;
}
double Manager::CalculateSalary()
{
    double salary;
    salary=Employee::CalculateSalary()+bonus;
    return salary;
}
 void Manager::displayInfo()
{
    Employee::displayInfo();
    cout<<getBonus()<<endl<<endl;
    //display employee info
}
Executive::Executive(string fn, string ln, string t, double sal,double b,double s):Manager(fn,ln,t,sal,b)
{
    setStockOption(s);
}
void Executive::setStockOption(double s)
{
    stockOption=s;

}
double Executive::getStockOption()const
{
    return stockOption;
}
void Executive::displayStockOption()
{
    cout<<stockOption;
}
double Executive::CalculateSalary()
{
    double salary;
    salary=Manager::CalculateSalary()+stockOption;
    return salary;

}
void Executive::displayInfo()
{
    CalculateSalary();
    cout<<"Info"<<endl<<"First:"<<getFirstName()<<endl<<"Last:"<<getLastName()<<endl
        <<"Title:"<<getJobTitle()<<endl<<"Salary:"<<getBaseSalary()<<endl<<"Bonus:"<<getBonus()
        <<endl<<endl;
    //display employee info
}
TechStaff::TechStaff(string fn,string ln,string t,double sal,double p):Employee(fn,ln,t,sal)
{
    setProfitShare(p);
}
double TechStaff::getProfitShare()const
{
    return profitshare;
}
void TechStaff::setProfitShare(double p)
{
    profitshare=p;
}
void TechStaff::displayProfitShare()
{
    cout<<profitshare;
}
void TechStaff::displayInfo()
{
    cout<<"Info"<<endl<<"First:"<<getFirstName()<<endl<<"Last:"<<getLastName()<<endl
        <<"Title:"<<getJobTitle()<<endl<<"Salary:"<<getBaseSalary()<<endl<<"Profit Share:"<<getProfitShare()
        <<endl<<endl;
    //display employee info
}
//software engineer functions
SoftEngineer::SoftEngineer(string fn, string ln, string t, double sal,double p,double o):TechStaff(fn,ln,t,sal,p)
{
    setOverTime(o);
}
double SoftEngineer::getOverTime()const
{
    return overTime;
}
void SoftEngineer::setOverTime(double o)
{
    overTime=o;
}
void SoftEngineer::displayOverTime()
{
    cout<<overTime;
}
void SoftEngineer::displayInfo()
{
    cout<<"Info"<<endl<<"First:"<<getFirstName()<<endl<<"Last:"<<getLastName()<<endl
        <<"Title:"<<getJobTitle()<<endl<<"Salary:"<<getBaseSalary()<<endl<<"Profit Share:"<<getProfitShare()
        <<getOverTime()<<endl<<endl;
    //display employee info
}
TestEngineer::TestEngineer(string fn, string ln, string t, double sal,double p):TechStaff(fn,ln,t,sal,p)
{

}
