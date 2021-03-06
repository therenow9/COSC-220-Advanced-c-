#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_1_employee.h"
#include "proj_1_aux_functions.h"
#include "proj_1_db_functions.h"
using namespace std;

void readDatabase(Employee* &eList,int &eCount)
{
    int num_lines=0;
    ifstream dataIn;
    string line;
    dataIn.open("employee.db");
    if ( dataIn.peek() == std::ifstream::traits_type::eof() )
    {
        eList=nullptr;
        eCount=0;
    }
    while(getline(dataIn,line))
    {
        //get number of lines in the file to sepcify e Count
        ++num_lines;
    }
    dataIn.close();
    dataIn.open("employee.db");
    eCount=num_lines;
    //set eCount to num_lines;
    eList=new Employee[eCount];
    for (int i=0; i<num_lines; i++)
    {
        string temp="";
        double temp_num=0;
        dataIn>>temp;
        eList[i].setFirstName(temp);
        dataIn>>temp;
        eList[i].setLastName(temp);
        dataIn>>temp;
        eList[i].setSSN(temp);
        dataIn>>temp;
        eList[i].setBirthDate(temp);
        dataIn>>temp_num;
        eList[i].setSalary(temp_num);
    }
}
void writeDatabase(Employee* &eList,int &eCount)
{
    ofstream dataOut;
    dataOut.open("employee.db");
    for (int i=0; i<eCount; i++)
    {
        //write employees back to database
        dataOut << eList[i].getFirstName()<<" "<<eList[i].getLastName()
                <<" "<<eList[i].getSSN()<<" "<<eList[i].getBirthDate()<<" "<<
                eList[i].getSalary()<<endl;
    }
    dataOut.close();
}
void retrieveEmployee(Employee* eList, int &eCount)
{
    int choice=10;
    string last_name="";
    string first_name="";
    string ssn="rtt";
    string birthday="";
    bool result=false;
    bool done=false;
    double salary=0;
    cout<<"How would you like to retrieve the information"<<
        endl<<"1 by SSN"<<endl<<"2 by last name"<<endl
        <<"3 by first name"<<endl<<"4 by birthday"<<endl<<"5 by salary"<<endl
        <<"6 to exit to main menu"<<endl<<endl;
    while(done==false)
    {
        while ((choice<1)||(choice>6))
        {
            //enter selection with error checking
            cout<<"Enter your choice:";
            cin>>choice;
        }
        switch(choice)
        {
        case 1:
            result=false;
            //SSN
            cout<<"Please enter the SSN of the employee you would like to search"<<endl;
            ssn=Validate_ssn();
            for (int i=0; i<eCount; i++)
            {
                if (ssn==eList[i].getSSN())
                {
                    printEmployee(eList[i]);
                    //print employee info if search matches
                    result=true;
                }
            }
            if (result==false)
            {

                cout<<"an employee with this information was not found"<<endl;
            }
            done=true;
            break;
        case 2:
            //last name
            result=false;
            cout<<"Please enter the last name of the Employee that you would like to search for"<<endl;
            last_name=Validate_last_name();
            for (int i=0; i<eCount; i++)
            {
                if (last_name==eList[i].getLastName())
                {
                    printEmployee(eList[i]);
                    //print employee info if search matches
                    result=true;

                }
            }
            if (result==false)
            {

                cout<<"An employee with this last name was not found"<<endl;
            }
            done=true;
            break;
        case 3:
            //firstname
            result=false;
            first_name=Validate_first_name();
            for (int i=0; i<eCount; i++)
            {
                if (first_name==eList[i].getFirstName())
                {
                    printEmployee(eList[i]);
                    //print employee info if search matches
                    result=true;
                }
            }
            if (result==false)
            {
                cout<<"An employee with this first name was not found"<<endl;
            }
            break;
            done=true;
        case 4:
            result=false;
            // birthday
            cout<<"Please enter the birthday of the employee that you would like to search for"<<endl;
            birthday=Validate_birthday();
            for (int i=0; i<eCount; i++)
            {
                if (birthday==eList[i].getBirthDate())
                {
                    printEmployee(eList[i]);
                    //print employee info if search matches
                    result=true;
                }
            }
            if (result==false)
            {
                cout<<"An employee with this birthday was not found"<<endl;
            }
            done=true;
            break;
        case 5:
            result=false;
            //salary
            cout<<"Please enter the salary of the employee that you would like to search for"<<endl;
            salary=Validate_salary();
            for (int i=0; i<eCount; i++)
            {
                if (salary==eList[i].getSalary())
                {
                    printEmployee(eList[i]);
                    //print employee info if search matches
                    result=true;
                }
            }
            if (result==false)
            {
                cout<<"An employee with this Salary was not found"<<endl;
            }
            done=true;
            break;
        case 6:
            done=true;
            break;
        default:
            cout<<"You have made an incorrect selection or an error has occurred"<<endl;
        }
    }
}
bool deleteEmployee(Employee *&eList, int &eCount)
{
    string ssn;
    bool success=false;
    int emp_no=0;
    char sure;
    cout<<"Please enter the SSN of the employee you want to delete"<<endl;
    ssn=Validate_ssn();
    for (int i=0; i<eCount; i++)
    {
        if (ssn==eList[i].getSSN())
        {
            success=true;
            printEmployee(eList[i]);
            //print employee info if search matches
            emp_no=i;
        }
    }
    if (success==false)
    {
        cout<<"An employee with this SSN was not found"<<endl;

    }
    cout<<"Are you sure you permanently want to delete this employee from the database?"<<endl<<"Y/N";
    cin>>sure;
    if (sure!='y'||sure!='Y'){

        success==false;
    }
    if (success==true)
    {
        Employee* newList=new Employee[eCount-1];
        for (int i=0; i<eCount-1; i++)
        {
            if (i<emp_no)
            {
                newList[i].setFirstName(eList[i].getFirstName());
                newList[i].setLastName(eList[i].getLastName());
                newList[i].setSSN(eList[i].getSSN());
                newList[i].setBirthDate(eList[i].getBirthDate());
                newList[i].setSalary(eList[i].getSalary());
            }
            else if(i>=emp_no)
                //skip 1
            {
                newList[i].setFirstName(eList[i+1].getFirstName());
                newList[i].setLastName(eList[i+1].getLastName());
                newList[i].setSSN(eList[i+1].getSSN());
                newList[i].setBirthDate(eList[i+1].getBirthDate());
                newList[i].setSalary(eList[i+1].getSalary());
                newList[i].setSalary(eList[i+1].getSalary());
            }
        }
        //set Elist back
        delete []eList;
        eList=newList;
        eCount-=1;
    }
    return success;
}

bool modifyEmployee(Employee* &eList,int &eCount)
{
    bool success=false;
    string ssn="";
    string name_first="JohndoeSmith";
    string name_last="JohndoeSmith";
    string birthday="b";
    bool no_letters=false;
    int emp_no=0;
    int salary=-1;
    int choice=10;
    cout<<"Please enter the SSN of the employee you want to modify"<<endl;
    ssn=Validate_ssn();
    for (int i=0; i<eCount; i++)
    {
        if (ssn==eList[i].getSSN())
        {
            success=true;
            printEmployee(eList[i]);
            //print employee info if search matches
            emp_no=i;
        }
    }
    cout<<"What information would you like to modify"<<
        endl<<"*SSN cannot be modified"<<endl<<"2 for last name"<<endl
        <<"3 for first name"<<endl<<"4 for birthday"<<endl<<"5 by salary"<<endl
        <<endl;
    while ((choice<2)||(choice>5))
    {
        //enter selection with error checking
        cout<<"Enter your choice:";
        cin>>choice;
        cout<<endl;
    }
    switch(choice)
    {
    case 2:
        //last name
        name_last=Validate_last_name();
        eList[emp_no].setLastName(name_last);
        cout<<"The last name has been modified successfully"<<endl;
        break;

    case 3:
        //firstname
        name_first=Validate_first_name();
        eList[emp_no].setFirstName(name_first);
        cout<<"The first name has been modified successfully"<<endl;
        //set first name
        break;
    case 4:
        // birthday
        birthday=Validate_birthday();
        eList[emp_no].setBirthDate(birthday);
        cout<<"The birthday has been modified successfully"<<endl;
        break;
    case 5:
        //salary
        salary=Validate_salary();
        eList[emp_no].setSalary(salary);
        cout<<"The salary has been modified successfully"<<endl;
        break;
    default:
        cout<<"You have made an incorrect selection or an error has occurred"<<endl;
        return success;
    }
}
bool insertEmployee(Employee* &eList,int &eCount)
{
    //function to insert new employee into the database
    bool success=false;
    string name_first="JohndoeSmith";
    string name_last="JohndoeSmith";
    string ssn="0";
    string birthday="b";
    double salary=-1;
    name_first=Validate_first_name();
    cout<<endl;
    name_last=Validate_last_name();
    cout<<endl;
    ssn=Validate_ssn();
    for (int i=0; i<eCount; i++)
    {
        if ( ssn==eList[i].getSSN())
        {
            //if SSN already exists end the program
            exit(1);
        }
    }
    cout<<endl;
    birthday=Validate_birthday();
    cout<<endl;
    salary=Validate_salary();
    Employee*newList=new Employee[eCount+1 ];
    for (int i=0; i<eCount; i++)
    {
        //do reassign
        newList[i]=eList[i];
    }
    newList[eCount].setFirstName(name_first);
    newList[eCount].setLastName(name_last);
    newList[eCount].setBirthDate(birthday);
    newList[eCount].setSSN(ssn);
    newList[eCount].setSalary(salary);
    delete []eList;
    eList=newList;
    //do reassignment
    success=true;
    eCount+=1;
    if (success=false)
    {

        cout<<"The insertion of data failed"<<endl;
        exit(1);
    }
    else
    {
        success=true;
        cout<<"The data was inserted successfully"<<endl;

    }
    return success;
}
void printDatabase(Employee* &eList, int &eCount);
void printDatabase(Employee* &eList, int &eCount)
{
    ifstream dataIn;
    cout << "----------------------------------------------------------------" << endl;
    cout <<setw(10)<< "  First"<<setw(11) <<"Last"<<setw(13)<<"SSN"<<setw(11)<<"DOB"<<setw(12)<<"SALARY" << endl;
    cout <<setw(10)<< "  Name"<<setw(11)<<" Name" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i=0; i<eCount; i++)
    {
//print all employees in the database
        printEmployee(eList[i]);

    }
};
void printEmployee(Employee Joe)
{
    cout <<setw(10)<< Joe.getFirstName()<<setw(13)<<
         Joe.getLastName()<<setw(13)<<Joe.getSSN()
         <<setw(11)<<Joe.getBirthDate()<<setw(10)<<
         Joe.getSalary()<<endl;
//display employee info
}
void displayMenu(Employee* eList,int &eCount)
{
    bool success=false;
    char choice = 'z';
    bool menu = true;
    char sure;
    do
    {
        cout<<endl;
        cout<<"--Database Menu--"<<endl;
        cout << "Type I for Insert" << endl;
        cout << "Type M for Modify" << endl;
        cout << "Type D for Delete" << endl;
        cout << "Type R for Retrieve" << endl;
        cout << "Type E to Exit and write changes to Database" << endl;
        cout << "Your Selection:";
        cin >> choice;
        choice=(toupper(choice));

        switch (choice)
        {
        case 'I':
            success=false;
            //insert function call
            success=insertEmployee(eList,eCount);
            if (success==true)
            {
                cout<<"The employee has been successfully added to the database"<<endl;

            }
            menu=true;
            break;
        case 'M':
            //modify function call
            modifyEmployee(eList,eCount);
            menu=true;
            break;
        case 'D':
            //insert delete call
            success=false;
            success=deleteEmployee(eList,eCount);
            if (success==true)
            {
                cout<<"The specified employee has been deleted successfully"<<endl;
            }
            menu=true;
            break;
        case 'R':
            //retrieve function call
            retrieveEmployee(eList, eCount);
            menu=true;
            break;
        case 'E':
            printDatabase(eList,eCount);
            cout<<endl<<"The above changes will be committed to the "<<endl
                <<"database file are you sure you want to save and exit?"
                <<endl<<"Y/N"<<endl;
            cin>>sure;
            if (sure=='Y'||sure=='y')
            {
                //confirm

                writeDatabase(eList,eCount);
                menu=false;
                exit(1);
            }
            else
            {
                //go back
                menu=true;
                break;
            }
        default:
            cout << "Invalid input try again"<<endl;
            menu=true;
            break;
        }
    }
    while (menu==true);
}


