#include <iostream>

using namespace std;
class Transportation
{
private:
    string owner;
    int year;
public:
    Transportation(string o,int y);
    void displayOwner();
    void displayYear();
    virtual void displayInfo();
};
Transportation::Transportation(string o,int y)
{
    owner=o;
    year=y;
}
void Transportation::displayYear()
{
    cout<<"Year: "<<year<<endl;
}
void Transportation::displayOwner()
{
    cout<<"Owner: "<<owner<<endl;
}
void Transportation::displayInfo()
{
    displayOwner();
    displayYear();
}
class Airplane:public Transportation
{
private:
    double altitude;
public:
    Airplane(string o,int y,double a);
    void displayAltitude();
    virtual void displayInfo();
};
Airplane::Airplane(string o,int y,double a):Transportation(o,y)
//derive and use overload constructor
{
    altitude=a;
}
void Airplane::displayAltitude()
{
    cout<<"Altitude: "<<altitude<<endl;
}
void Airplane::displayInfo()
{
    displayOwner();
    displayYear();
    displayAltitude();
}
class Helicopter:public Airplane
{
private:
    int propellers;
public :
    Helicopter(string o,int y,double a, int p);
    void displayPropellers();
    virtual void displayInfo();

};
class Jetplane:public Airplane
{
private:
    string airline;
public :
    Jetplane(string o,int y,double a, string airl);
    void displayAirline();
    virtual void displayInfo();

};
class Boat:public Transportation
{
private:
    int motors;
public:
    void displayMotors();
    virtual void displayInfo();
};
class SpeedBoat:public Boat
{
private :
    double topSpeed;
public:
    void displayTopSpeed();

};
class CruiseBoat:public Boat
{
private :
    int capacity;
public:
    void displayCapacity();

};
class Vehicle(string type,string model):public Transportation
{
private:
    string type;
    string model;
public:
    virtual void displayInfo();
};
class Car:public Vehicle
{
private:
    int fuelEff;
public:
    void displayfuelEff ());
    virtual void displayInfo();
};
class Truck:public Vehicle
{
private:
    string color;
    string wheels;
public:
    void displayWheels();
    void displayColor();
    virtual void displayInfo();
};
int main()
{
    //main to show virtual functions with dynamic binding\
    //trasnp
    Transportation trans("Jeremy",2000);
    cout<<"Transporation"<<endl;
    trans.displayInfo();
    //planes
    Airplane airp("Billy",2000,5600);
    cout<<"Airplane"<<endl;
    airp.displayInfo();
    Helicopter heli("Jack",2005,4600);
    cout<<"Helicopter"<<endl;
    heli.displayInfo();
    Jetplane jetp("Howard",2011,8700);
    cout<<"Jetplane"<<endl;
    jetp.displayInfo();
    //boats
    Boat boat("Charles",2003,2);
    cout<<"Boat"<<endl;
    boat.displayInfo();
    SpeedBoat speedboat("Mike",2006,3,80.7);
    cout<<"SpeedBoat"<<endl;
    speedboat.displayInfo();
    CruiseBoat cruiseboat("Tony",1998,6,500);
    cout<<"SpeedBoat"<<endl;
    cruiseboat.displayInfo();
    //vehicles
    Vehicle vehicle("Hailey",1995,"Honda","Accord");
    cout<<"Vehicle"<<endl;
    vehicle.displayInfo();
    Car car("Andy",2002,"Toyota","Rav4",17);
    cout<<"Car"<<endl;
    car.displayInfo();
    Truck truck("Kevin",2002,"Ford","f250","Green",6);
    cout<<"Vehicle"<<endl;
    truck.displayInfo();
    return 0;
}
