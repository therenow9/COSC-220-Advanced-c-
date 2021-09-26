#include "functions.h"
using namespace std;

int main()
{
    int start_x;
    int start_y;
    int num=-1;
    bool done=false;
    cout<<"Please enter the number of the maze that you would like to solve (0-16):"<<endl;
    while (num<0||num>16)
    {
        cin>>num;
    }
    num=100+num;
    string maze_no=std::to_string(num);
    //get which maze you want to solve
    char maze [6][6];
    readmaze(maze,maze_no);
    findStart(maze,start_x,start_y);
    //find the start coordinates of the maze
    print2dArray(maze);
    cout<<endl;


    done=findPath ( start_x, start_y,  maze,start_x, start_y,maze_no);
    //run recursive sequence
    if (done==false)
        //when finished
    {
        writeOutput(done,maze,maze_no);
    }


    return 0;
}



