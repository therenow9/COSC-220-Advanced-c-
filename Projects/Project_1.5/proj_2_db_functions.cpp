#include <iostream>
#include <iomanip>
#include <fstream>
#include "proj_2_employee.h"
#include "proj_2_aux_functions.h"
#include "proj_2_db_functions.h"
#include "Link.h"
using namespace std;

template <typename T>
void readDatabase(node<T>* &eList,int &eCount)
{
    node <T> *curr;
    node<T> *head=eList;
    int num_lines=0;
    ifstream dataIn;
    string line;
    dataIn.open("employeeSorted.db");
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
    dataIn.open("employeeSorted.db");
    eList=nullptr;
    eCount=num_lines;
    //set eCount to num_lines;
    for (int i=0; i<num_lines; i++)
    {
        Employee emp;
        dataIn>>emp;
        curr=new node <Employee>(emp,curr);
    }
    eList=curr;
    SSN_sort(eList,eCount);

}
template <typename T>
void writeDatabase(node<T>* &eList,int &eCount)
{
    node <T> *Curr;
    Curr=eList;
    ofstream dataOut;
    dataOut.open("employeeSorted.db");
    for (int i=0; i<eCount; i++)
    {
        //write employees back to database
        dataOut << (Curr->nodeValue).getFirstName()<<" "<< (Curr->nodeValue).getLastName()<<" "
<< (Curr->nodeValue).getSSN()<<" "<< (Curr->nodeValue).getBirthDate()<<" "<< (Curr->nodeValue).getSalary()<<endl;
Curr=Curr->next;
    }
    dataOut.close();
}
template <typename T>
void retrieveEmployee(node<T>* &eList, int &eCount)
{
    node <T> *Curr;
    Curr=eList;
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
                if (ssn==Curr->nodeValue.getSSN())
                {
                    printEmployee(Curr->nodeValue);
                    //print employee info if search matches
                    result=true;
                }
                Curr=Curr->next;
            }
            Curr=eList;
            if (result==false)
            {
                cout<<"an employee with this information was not found"<<endl;
            }
            done=true;
            break;
        case 2:
            //last name
            Curr=eList;
            result=false;
            cout<<"Please enter the last name of the Employee that you would like to search for"<<endl;
            last_name=Validate_last_name();
            for (int i=0; i<eCount; i++)
            {
                if (last_name==Curr->nodeValue.getLastName())
                {
                    printEmployee(Curr->nodeValue);
                    //print employee info if search matches
                    result=true;
                }
                Curr=Curr->next;
            }
            eList=Curr;
            if (result==false)
            {

                cout<<"An employee with this last name was not found"<<endl;
            }
            done=true;
            break;
        case 3:
            //firstname
            Curr=eList;
            result=false;
            first_name=Validate_first_name();
            for (int i=0; i<eCount; i++)
            {
                if (first_name==Curr->nodeValue.getFirstName())
                {
                    printEmployee(Curr->nodeValue);
                    //print employee info if search matches
                    result=true;
                }
                Curr=Curr->next;
            }
            Curr=eList;
            if (result==false)
            {
                cout<<"An employee with this first name was not found"<<endl;
            }
   	    done=true;
            break;
        case 4:
            Curr=eList;
            result=false;
            // birthday
            cout<<"Please enter the birthday of the employee that you would like to search for"<<endl;
            birthday=Validate_birthday();
            for (int i=0; i<eCount; i++)
            {
                if (birthday==Curr->nodeValue.getBirthDate())
                {
                    printEmployee(Curr->nodeValue);
                    //print employee info if search matches
                    result=true;
                }
                Curr=Curr->next;
            }
            Curr=eList;
            if (result==false)
            {
                cout<<"An employee with this birthday was not found"<<endl;
            }
            done=true;

            break;
        case 5:
            Curr=eList;

            result=false;
            //salary
            cout<<"Please enter the salary of the employee that you would like to search for"<<endl;
            salary=Validate_salary();
            for (int i=0; i<eCount; i++)
            {
                if (salary==Curr->nodeValue.getSalary())
                {
                    printEmployee(Curr->nodeValue);
                    //print employee info if search matches
                    result=true;
                }
                Curr=Curr->next;
            }
            Curr=eList;
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
template <typename T>
bool deleteEmployee(node<T>* &eList, int &eCount)
{
    node <T> *Curr;
    Curr=eList;
    string ssn;
    bool success=false;
    int emp_no=0;
    char sure;
    cout<<"Please enter the SSN of the employee you want to delete"<<endl;
    ssn=Validate_ssn();
    for (int i=0; i<eCount; i++)
    {
        if (ssn==Curr->nodeValue.getSSN())
        {
            success=true;
            printEmployee(Curr->nodeValue);
            //print employee info if search matches
            if (success==true)
            {

                cout<<"Are you sure you permanently want to delete this employee from the database?"<<endl<<"Y/N"<<endl;
                cin>>sure;
                if (sure!='y'||sure!='Y')
                {

                    success==false;
                }
                if (success==true)
                {
                    DeleteNode(eList,Curr->nodeValue);
                    eCount-=1;
                }
            }
        }
        Curr=Curr->next;
    }
    if (success==false)
    {
        cout<<"An employee with this SSN was not found"<<endl;
    }

    return success;
}
template <typename T>
bool modifyEmployee(node<T>* &eList,int &eCount)
{
    node <T> *Curr;
    Curr=eList;
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
        if (ssn==Curr->nodeValue.getSSN())
        {
            success=true;
            printEmployee(Curr->nodeValue);
            //print employee info if search matches
        }
        if (success==false)
        {
            Curr=Curr->next;
        }
        else if (success==true)
        {
            i=eCount;
//endit
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
        Curr->nodeValue.setLastName(name_last);
        cout<<"The last name has been modified successfully"<<endl;
        break;

    case 3:
        //firstname
        name_first=Validate_first_name();
        Curr->nodeValue.setFirstName(name_first);
        cout<<"The first name has been modified successfully"<<endl;
        //set first name
        break;
    case 4:
        // birthday
        birthday=Validate_birthday();
        Curr->nodeValue.setBirthDate(birthday);
        cout<<"The birthday has been modified successfully"<<endl;
        break;
    case 5:
        //salary
        salary=Validate_salary();
        Curr->nodeValue.setSalary(salary);
        cout<<"The salary has been modified successfully"<<endl;
        break;
    default:
        cout<<"You have made an incorrect selection or an error has occurred"<<endl;
        return success;
    }
    eList=Curr;
    //set back
    bool temp=true;
    return temp;
}
template <typename T>
bool insertEmployee(node<T>* &eList,int &eCount)
{
    //function to insert new employee into the database
    node <T> *Curr;
    Curr=eList;
    Employee emp;
    //define employee variable to be added to database
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
        if ( ssn==Curr->nodeValue.getSSN())
        {
            //if SSN already exists end the program
            exit(1);
        }
        Curr=Curr->next;
    }
    cout<<endl;
    birthday=Validate_birthday();
    cout<<endl;
    salary=Validate_salary();
    emp.setFirstName(name_first);
    emp.setLastName(name_last);
    emp.setBirthDate(birthday);
    emp.setSSN(ssn);
    emp.setSalary(salary);

    InsertNode(eList,emp);


    //do reassignment
    success=true;
    eCount+=1;
    if (success==false)
    {

        cout<<"The insertion of data failed"<<endl;
        exit(1);
    }
    else
    {
        success=true;
        cout<<"The data was inserted successfully"<<endl;

    }
    SSN_sort(eList,eCount);
    return true;
}
template <typename T>
void printDatabase(node <T>* eList, int &eCount)
{
    node <T> *Curr;
    Curr=eList;
    cout << "----------------------------------------------------------------" << endl;
    cout <<setw(10)<< "  First"<<setw(11) <<"Last"<<setw(13)<<"SSN"<<setw(11)<<"DOB"<<setw(12)<<"SALARY" << endl;
    cout <<setw(10)<< "  Name"<<setw(11)<<" Name" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i=0; i<eCount; i++)
    {
//print all employees in the database
       cout<<Curr->nodeValue;
        Curr=Curr->next;
        //move to next
    }
};
void printEmployee(Employee Joe)
{
    cout<<Joe;

}
template <typename T>
void displayMenu(node<T>* &eList,int &eCount)
{
    node <T> *Curr;
    Curr=eList;
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
        cout<<"Type S to Sort and Print the Database"<<endl;
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
        case 'S':
            sort_database(eList,eCount,6,true);
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
template <typename T>
void SSN_sort(node<T>* &head,int &eCount)
{
    //sort after inserting a new node
    node<Employee>* temp_1;
    node<Employee>* temp_2;
    node<Employee>* printMe;
    node<Employee>* Curr=head;
    temp_1=printMe;
    temp_2=printMe;
    for (int i=0; i<eCount; i++)
    {
        printMe=new node <Employee> (Curr->nodeValue,printMe);
        //do assignment
        Curr=Curr->next;
        //set next;
    }
    for (int i=0; i<eCount; i++)
    {
        temp_1=printMe;
        for (int j=0; j<eCount-1-i; j++)
        {
            temp_2=temp_1->next;
            if(temp_1->nodeValue.getSSN_NoDash()>temp_2->nodeValue.getSSN_NoDash())
            {
                Employee temp=temp_2->nodeValue;
                temp_2->nodeValue=temp_1->nodeValue;
                temp_1->nodeValue=temp;
                //reset variable
            }
            temp_1=temp_1->next;
        }
    }
    head=temp_1;
    //reset
}


template <typename T>
void sort_database(node<T>* head,int &eCount,int choice=1,bool display =false)
{
    node<T>* temp_1;
    node<T>* temp_2;
    node<T>* printMe;
    node<T>* Curr=head;
    //decalare
    for (int i=0; i<eCount; i++)
    {
        printMe=new node <Employee> (Curr->nodeValue,printMe);
        //do assignment
        Curr=Curr->next;
        //set next;
    }
    temp_1=printMe;
    temp_2=printMe;
    //decalare variables for swap
    if (choice==6)
    {
        while (choice<1||choice>4)
        {
            cout<<"Please enter the way you would like the database to be sorted"<<endl
                <<"1 by ssn"<<endl<<"2 By last name(then by first)"<<endl<<
                "3 by birthday"<<endl<<"4 by income"<<endl;
            cin>>choice;
        }
    }
    else
    {
        choice=1;
        //print ssn by default
    }
    switch (choice)
    {
    case 1:
        printMe=head;
        //sort by ssn
        break;
    case 2:
        //sort by last name (then first)
        for (int i=0; i<eCount; i++)
        {
            temp_1=printMe;
            for (int j=0; j<eCount-1-i; j++)
            {
                temp_2=temp_1->next;
                if(temp_1->nodeValue.getLastName()>temp_2->nodeValue.getLastName())
                {
                    Employee temp=temp_2->nodeValue;
                    temp_2->nodeValue=temp_1->nodeValue;
                    temp_1->nodeValue=temp;
                    //reset variable
                }
                else if(temp_1->nodeValue.getLastName()==temp_2->nodeValue.getLastName())
                {
                    if(temp_1->nodeValue.getFirstName()>temp_2->nodeValue.getFirstName())
                    {
                        Employee temp=temp_2->nodeValue;
                        temp_2->nodeValue=temp_1->nodeValue;
                        temp_1->nodeValue=temp;
                        //reset variable
                    }


                }
                temp_1=temp_1->next;
            }
        }
        break;
    case 3:
        //sort by birthday
        for (int i=0; i<eCount; i++)
        {
            temp_1=printMe;
            for (int j=0; j<eCount-1-i; j++)
            {
                temp_2=temp_1->next;
                if(temp_1->nodeValue.getBirthDate().compare(6,9,temp_2->nodeValue.getBirthDate(),6,9)>0)
                {
                    //year
                    Employee temp=temp_2->nodeValue;
                    temp_2->nodeValue=temp_1->nodeValue;
                    temp_1->nodeValue=temp;
                    //reset variable
                }
                else if(temp_1->nodeValue.getBirthDate().compare(6,9,temp_2->nodeValue.getBirthDate(),6,9)==0)
                    //if years are the same
                {
                    if(temp_1->nodeValue.getBirthDate().compare(0,2,temp_2->nodeValue.getBirthDate(),0,2)>0)
                    {
                        //then sort by month
                        Employee temp=temp_2->nodeValue;
                        temp_2->nodeValue=temp_1->nodeValue;
                        temp_1->nodeValue=temp;
                        //reset variable
                    }
                    else if(temp_1->nodeValue.getBirthDate().compare(0,2,temp_2->nodeValue.getBirthDate(),0,2)>0)
                        //if months are the same
                    {
                        if(temp_1->nodeValue.getBirthDate().compare(3,2,temp_2->nodeValue.getBirthDate(),3,2)>0)
                            //then sort by day
                        {
                            Employee temp=temp_2->nodeValue;
                            temp_2->nodeValue=temp_1->nodeValue;
                            temp_1->nodeValue=temp;
                            //reset variable
                        }
                    }
                }
                temp_1=temp_1->next;
                //go to next
            }
        }
        break;
    case 4:
        //sort by income
        for (int i=0; i<eCount; i++)
        {
            temp_1=printMe;
            for (int j=0; j<eCount-1-i; j++)
            {
                temp_2=temp_1->next;
                if(temp_1->nodeValue.getSalary()>temp_2->nodeValue.getSalary())
                {
                    Employee temp=temp_2->nodeValue;
                    temp_2->nodeValue=temp_1->nodeValue;
                    temp_1->nodeValue=temp;
                    //reset variable
                }
                temp_1=temp_1->next;
            }
        }
        break;
    }
    if (display==true)
    {
        printDatabase(temp_1,eCount);

    }
}

