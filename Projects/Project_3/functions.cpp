
void readmaze(char maze[][6],string mazeno)
//function to read in the maze
{
    ifstream dataIn;
    string maze_no="maze"+mazeno+".txt";
    dataIn.open(maze_no);
    //open the maze you want to solve
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            char temp;
            dataIn>>temp;
            maze[i][j]=temp;
        }
    }
    dataIn.close();

}
void print2dArray(char maze[][6])
//function to print the maze
{
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}
void findStart(char maze[][6],int &start_x, int &start_y)
//function to find the starting coordinates of the maze
{
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            if (maze [i][j]=='S')
            {
                start_x=i;
                start_y=j;
            }
        }
    }

}
void writeOutput(bool solved,char maze[][6],string maze_no)
{
    ofstream dataOut;
    string sol="sol"+maze_no+".txt";
    dataOut.open(sol);
    //create new file for the output
    if (solved==true)
    {

        for (int i=0; i<6; i++)
        {
            for (int j=0; j<6; j++)
            {
                dataOut<<maze[i][j]<<" ";
            }
            dataOut<<endl;
        }
    }

    else
        //if false write that there is no solution
    {
        cout<<"Maze "<<maze_no<<" has no solution."<<endl;
        dataOut<<"Maze "<<maze_no<<" has no solution."<<endl;
    }
    dataOut.close();
}

bool findPath (int row, int col, char maze[][6],int start_x,int start_y,string maze_no)
{
    if (row<0||row>5||col<0||col>5)
    {
        //prevent from going out of bounds
        return false;
    }
    if (maze[row][col]=='F')
        //if at the finish
    {
        bool done=true;
        maze [start_x][start_y]='S';
        print2dArray(maze);
        writeOutput(done,maze,maze_no);
        //write output of maze with Xs to file
        return true;
    }
    if (maze[row][col]=='0'||maze[row][col]=='X')
    {
        return false;
    }
    else
    {
        maze[row][col] = 'X';
        if (findPath(row, col+1,maze,start_x,start_y,maze_no)==true)
        {
            return true;
        }

        if (findPath(row+1, col, maze,start_x,start_y,maze_no)==true)
        {
            return true;
        }

        if (findPath(row-1, col, maze,start_x,start_y,maze_no)==true)
        {
            return true;
        }

        if(findPath(row, col-1, maze,start_x,start_y,maze_no)==true)
        {
            return true;
        }
        maze[row][col]='1';
        return false;
    }
}


