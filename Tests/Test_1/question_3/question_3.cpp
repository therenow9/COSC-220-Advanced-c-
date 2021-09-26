# include <iostream>

using namespace std;
#include <iostream>
class car
{
public:
//constructors
    car();
    car(string c,int y);
    void setColor(string c);
    void setYear(int y);
    int getYear();
    string getColor();
private:
    string color;
    int year;


};
car::car()
{
    color="Blank";
    year=0000;

}
car::car(string c,int y)
{
    color=c;
    year=y;
}
void car::setColor(string c)
{
    color=c;

}
void car::setYear(int y)
{
    year=y;

}
string car::getColor()
{
    return color;

}
int car::getYear()
{
    return year;

}
car *createCarArray(int size);
car *createCarArray(int size)
{
    car *carArr=new car [size];
    return carArr;



}
class person
{
public:
//constructors
    person();
    person(string n,car c);
    void setName(string n);
    void setCar(car c);
    string getName();
    car getCar();
private:
    car mycar;
    string myname;


};
person::person()
{
    myname="John";
    mycar=car();

}
person::person(string n,car c)
{
    myname=n;
    mycar=c;
}
void person::setCar(car c)
{
    mycar=c;

}
void person::setName(string n)
{
    myname=n;

}
car person::getCar()
{
    return mycar;

}
string person::getName()
{
    return myname;

}
person *createpersonArray(int size);
person *createpersonArray(int size)
{
    people *peopleArr=new person[size]
    return peopleArr;



}

int main()
{



    return 0;
}
