#include "Lab_9.cpp"

using namespace std;
//Lab 9
//Jeremy Scheuerman
//Dr.  Wang
//March 29 2021
int main()
{
    Employee empArr[3];
//define the 3 arrays
    Executive emp0("Bill","Muhlenfeld","CFO",100000,6500,2500);
    SoftEngineer emp1("Kevin","Weller","Head Developer",150000,3500,10000);
    TestEngineer emp2("Andrew","McGinnity","Head Tester",1500000,4500);

    empArr[0]=emp0;
    empArr[1]=emp1;
    empArr[2]=emp2;

    empArr[0].displayInfo();
    empArr[1].displayInfo();
    empArr[2].displayInfo();


    emp0.displayInfo();
    emp1.displayInfo();
    emp2.displayInfo();
    //Lab 9

    Employee *empptr;
    empptr=new Employee("Neo","Anderson","Project Manager",100000);
    empptr->displayInfo();
      empptr=new Executive("Tyrell","Wellick","Project Manager",156300,7500,4534);
    empptr->displayInfo();
    empptr=new SoftEngineer("Eliot","Alderson","Cyber security Engineer",13300,4534,4500);
    empptr->displayInfo();




    return 0;
}
