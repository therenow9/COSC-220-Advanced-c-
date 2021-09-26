class Circle
{
private:
    double radius;
public:
    Circle(double radius=0);
    void CircleSetRadius(double rad);
    double CircleGetRadius();

};
void Circle::CircleSetRadius(double rad)
{


    radius=rad;
}
double Circle::CircleGetRadius()
{
    return radius;

}

class Cylinder{
private:
float height;
double radius;
Circle base;
public:
Cylinder(float h=0,Circle base());
Cylinder(float height,Circle base(double radius));
void CylinderSetHeight(double h);
void CylinderSetBase(Circle base());
float CylinderGetHeight(double h);
Circle CylinderGetBase(Circle base());

};
void Cylinder(float h,Circle base(double r){
height=h;
radius=r;

}



