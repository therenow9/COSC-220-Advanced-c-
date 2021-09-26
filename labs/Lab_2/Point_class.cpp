#include <cmath>
class Point
{
private:
    float x,y;
public:
    Point();
    Point(float xc,float yc);
    void setX(float xc);
    void setY(float yc);
    float getX()const;
    float getY()const;

};

Point::Point()
{
    x=0.0;
    y=0.0;

}
Point::Point(float xc,float yc)
{
    x=xc;
    y=yc;

}
void Point::setX(float xc)
{
    x=xc;
}
void Point::setY(float yc)
{
    y=yc;
}
float Point::getX()const
{
    return x;
}
float Point::getY()const
{
    return y;
}
float operator+(Point lhs,Point rhs)
{
    float dist;

    dist =sqrt(pow((lhs.getX()-rhs.getX()), 2)+pow ((lhs.getY()-rhs.getY()),2));
    return dist;

}
