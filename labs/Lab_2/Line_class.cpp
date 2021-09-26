#include "Point_class.cpp"
#include <iostream>
using namespace std;
class Line
{
public:
    //constructors
    Line();
    Line(Point b, Point e);
    //set the beginning point of the Line
    void setBegin(Point b);
    //set the end point of the line
    void setEnd(Point e);
    //return the Length of the line segment
    double getLength() const;
    //display the x and y coordinate of begin and end point
    void showCoordinate() const;
private://Point is the class defined in Question4
    Point begin;
    Point end;
};
Line::Line()
{
    begin = Point();
    end = Point();
}

Line::Line(Point b, Point e)
{
    begin = b;
    end = e;
}

void Line::setBegin(Point b)
{
    begin = b;
}

void Line::setEnd(Point e)
{
    end = e;
}

double Line::getLength() const
{
    return begin + end;
}

void Line::showCoordinate() const
{
    cout << "Begin coordinate: " << endl
         << "x: " << begin.getX()
         <<endl<< "y: " << begin.getY() << endl << endl;

    cout << "End coordinate: " << endl
         << "x: " << end.getX()<<endl
         << "y: " << end.getY() <<endl;
}


