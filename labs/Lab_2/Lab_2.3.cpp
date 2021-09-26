#include <iostream>
#include <iomanip>
#include "Line_class.cpp"
using namespace std;


Line *MakeLineArray(int size)
{

    //constructs and returns an array of Line objects
    Line *line_arr=new Line [size];
    return line_arr;
}
Line Shortest (Line *ptr,int size)
{
    int shortest=0;
    for (int i=1; i<size; i++)
    {
        if (ptr[shortest].getLength()>ptr[1].getLength())
        {
            shortest=1;

        }

    }
    return ptr[shortest];

}
void sortLine(Line * ptr, int size)
{
    //use bubble sort to sort arrays
    for (int i=0; i<size; i++)
    {

        if (ptr[0].getLength()>ptr[i].getLength())
        {
            swap(ptr[0],ptr[i]);
        }

    }
}

int main()
{
    Line * ptr,longest;
    float x1,y1;
    float x2,y2;
    float distance;
    int size=100;
    ptr=MakeLineArray(size);

    for (int i=0; i<size; i++)
    {
        Point begin_pt;
        Point end_pt;
        begin_pt.setX(rand()%100+1);
        begin_pt.setY(rand()%100+1);
        end_pt.setX(rand()%100+1);
        end_pt.setY(rand()%100+1);

        ptr[i].setBegin(begin_pt);
        ptr[i].setEnd(end_pt);

    }
    Shortest(ptr,size);

    Shortest(ptr,size).showCoordinate();
    return 0;

}
