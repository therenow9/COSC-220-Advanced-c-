//Jeremy Scheuerman
//Lab 2
//Dr. Wang
//Find average of 2darray
//
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
const int rows=5;
const int col=10;
void findAverage(int arr[][col],int rows,float avg[])
{
    //function to find average of rows in 2d array
    for (int i=0; i<rows; i++)
    {
        float sum=0;
        for (int j=0; j<3; j++)
        {
            sum+= arr[i][j];
        }
        avg[i]=sum/3;
        cout<<"The average of row "<<i+1<<" is "<<setprecision(4)<<avg[i]<<endl;
    }
}

int main()
{
    srand(time(NULL));
    //declare 2d array values
    int two_d_arr[rows][col];
    for (int i=0; i<rows; i++)
    {
        cout<<"Row "<<i+1<<": ";
        for (int j=0; j<col; j++)
        {
            two_d_arr[i][j]=rand() %80+20;
            cout<<two_d_arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    float avg[5];
    //declare average array
    findAverage(two_d_arr,rows,avg);
    return 0;
}

