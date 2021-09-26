#include "Lab_8.h"

using namespace std;
//Lab 8
//Jeremy Scheuerman
//Dr.  Wang
//March 17 2021
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
    
    return 0;
}
