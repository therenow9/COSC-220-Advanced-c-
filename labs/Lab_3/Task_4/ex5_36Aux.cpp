//Auxilary Functions file
//Lab 3 Task 3
//COSC 220
//Jeremy Scheuerman

#include <iostream>
#include "ex5_36Aux.h"
#include "d_rect.h"

using namespace std;
rectangle **getRoomArray()
{
    //this function gets an array of rooms using the rectangle object
    int size;

    cout<<"Input the number of rooms"<<endl;
    cin>>size;

    rectangle * obj_room=nullptr;
    obj_room=new rectangle [size];
//init
    rectangle **room=nullptr;
    room=new rectangle*[size+1];
    for (int i=0; i<size; i++)
    {
        room[i]=obj_room+i;
        //set array values
    }
    room[size]=nullptr;
    return room;

}

void getRoomData(rectangle **rooms)
//set length and width of each room
{
    double length;
    double width;
    int num_rooms=0;
    do
    {
        cout<<"Input the length of room "<<num_rooms<<":"<<endl;
        cin>>length;
        cout<<"Input the width of room "<<num_rooms<<":"<<endl;
	cin>>width;
        (*rooms[num_rooms]).setSides(length,width);
        num_rooms++;
    }
    while (rooms[num_rooms]!=nullptr);
}

double getTotalArea(rectangle **rooms)
{
//gets total area of a room if not null

    double area=0;
    int num_rooms=0;
    do
    {
        area+=(*rooms[num_rooms]).area();
        num_rooms++;
    }
    while (rooms[num_rooms]!=nullptr);
    //keep doing as long as not null
    return area;
}

rectangle largestPerimeter(rectangle **rooms)
{
    //finds the largest perimeter out of all rooms
    rectangle largest_perim=*rooms[0];
    int num_rooms=1;
    do
    {
        rectangle temp=*rooms[num_rooms];
        if(largest_perim.perimeter()<temp.perimeter())
            //do comparison of rectangles
        {
            largest_perim=temp;
        }
        num_rooms++;
    }
    while (rooms[num_rooms]!=nullptr);
    return largest_perim;
}

void reportOnLargest(rectangle & largeRoom)
//prints out the stats of the largest room
{
    cout<<"Here are the stats of the Largest Room:"<<endl
        <<"Length: "<<largeRoom.getLength()<<endl<<
        "Width: "<<largeRoom.getWidth()<<endl
        <<"Perimeter: "<<largeRoom.perimeter()<<endl;


}
void reportOnTotalArea(rectangle ** rooms)
{
    cout<<"Here is the total area of all rooms"<<endl
        <<getTotalArea(rooms)<<endl;

}
