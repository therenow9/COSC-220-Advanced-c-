#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string Validate_first_name()
{
    string name_first="JohnDoeSmith";
    while ((name_first.length()>9)||(name_first.length()==0))
    {
        //get name with error checking
        cout<<"Please enter your first name (10 letters or less)"<<endl;
        cin>>name_first;
    }
    return name_first;

}
string Validate_last_name()
{
    string name_last="JohnDoeSmith";
    while ((name_last.length()>10)||(name_last.length()==0))
    {
        //get name with error checking
        cout<<"Please enter your last name (10 letters or less)"<<endl;
        cin>>name_last;
        if (name_last.length()>10)
        {
            cout<<"This last name is too long"<<endl;

        }
    }
    return name_last;
}
string Validate_birthday()
{
    string birthday="1";
    bool success;
    do
    {
        success=true;
        cout<<"Please enter your birthday in the following format MM-DD-YYYY"<<endl;
        cin>>birthday;

        if (birthday.length()>10)
        {

            cout<<"The birthday is too long"<<endl;
            success=false;
        }
        else if(birthday.length()<10)
        {
            cout<<"The birthday is too short"<<endl;
            success=false;
        }
        else
        {
            for (int i=0; i<birthday.length(); i++)
                //check for any letters
            {
                if ((i==2)||(i==5))
                {
                    if (birthday.at(i)!='-')
                    {
                        success=false;
                        cout<<"Missing a dash at place "<<i+1<<endl;
                    }
                }
                else if (isdigit(birthday.at(i))==false)
                {
                    cout<<"character at place "<<i+1<<" is not a digit"<<endl;
                    success=false;
                }
            }
        }
    }
    while (success==false);
    return birthday;
}
string Validate_ssn()
{
    bool success;
    string ssn="0";
    do
    {
        success=true;
        cout<<"Please enter your SSN in the following format 123-45-6789"<<endl;
        cin>>ssn;
        if (ssn.length()>11)
        {

            cout<<"The ssn is too long"<<endl;
            success=false;
        }
        else if(ssn.length()<11)
        {

            cout<<"The ssn is too short"<<endl;
            success=false;
        }
        else
        {

            for (int i=0; i<ssn.length(); i++)
                //check for any letters
            {
                if ((i==3)||(i==6))
                {
                    if(ssn.at(i)!='-')
                    {
                        success=false;
                        cout<<"Missing a dash at place "<<i+1<<endl;
                    }
                }
                else if(isdigit(ssn[i])==false)
                {
                    cout<<"character at place "<<i+1<<" is not a digit"<<endl;
                    success=false;
                }
            }
        }
    }
    while (success==false);
    return ssn;

}
double Validate_salary()
{
    double salary=-1;
    while (salary<0)
    {
        cout<<"Please enter your Salary"<<endl;
        cin>>salary;
    }
    return salary;

}
