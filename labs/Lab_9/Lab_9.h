 #ifndef EMP
#define EMP
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Employee
//base class employee
{
private:
    string firstName;
    string lastName;
    string title;
    double baseSalary;

public:
    //define constructors
    Employee(string fn="John",string ln="Doe",string title="intern",double sal=45000);
    //define getter/setter for firstName,lastName,salary
    string getFirstName()const;
    string getLastName()const;
    string getJobTitle()const;
    double getBaseSalary()const;
    //note but const for getters
    void setFirstName(string fn);
    void setLastName(string ln);
    void setJobTitle(string t);
    void setBaseSalary(double sal);
    void displayJobTitle();
    void displayBaseSalary();
    void displayName();
    virtual void displayInfo();
    double CalculateSalary();
};
//derived class manager
class Manager:public Employee
{
private:
    double bonus;
public:
    Manager(string fn,string ln,string title,double sal,double b=5000);

    //constructor
    double getBonus()const;
    void setBonus(double b);
    void displayBonus();
    double CalculateSalary();
    //overwrite calc salary to include bonus
    void displayInfo();
    //overwrite display info function to incorporate profit sharing
};
class Executive:public Manager
{
private:
    double stockOption;
public:
    Executive();
    //constructor
    Executive(string fn, string ln, string t, double sal,double b,double s);
    //constructor with default values
    double getStockOption()const;
    void setStockOption(double s);
    void displayStockOption();
    double CalculateSalary();
    //overwrite calc salary to include bonus and stock option
    void displayInfo();
    //overwrite display info function to incorporate profit sharing and stock option

};
class TechStaff:public Employee
//derived class technical staff
{
private:
    double profitshare;
public:
    //constructor
   TechStaff(string fn,string ln,string t,double sal,double p);
    double getProfitShare()const;
    void setProfitShare(double p);
    void displayProfitShare();
    double CalculateSalary();
    void displayInfo();
    //overwrite display info function to incoroporate profit sharing
};

class SoftEngineer:public TechStaff
{
private:
    double overTime;
public:
    //constructor
    SoftEngineer(string fn, string ln, string t, double sal,double p,double o);
    double getOverTime()const;
    void setOverTime(double o);
    void displayOverTime();
    void displayInfo();
    //overwrite display info class to include overtime
};
class TestEngineer:public TechStaff
{
public:
    //constructor
    TestEngineer(string fn, string ln, string t, double sal,double p);
};
//#include "Lab_8.cpp"
#endif
