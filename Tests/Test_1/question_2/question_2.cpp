# include <iostream>

using namespace std;

void getMost(int arr[][5],int rows);
void getMost(int arr[][5],int rows)
{
    day-;
    cout<<"enter a day to check"<<endl;
    cin>>day;
    cout<<"Subject studied the most for on day "<<day<<"  is"<<endl;
    int j;
    int subject;
    int most=0;
    for (int i=0; i<4; i++)
    {
        for (j=0; j<rows; j++)
        {
            if (arr[i][j]>most)
            {
                subject=i;
                arr[i][j]=most;
            }
        }

        cout<<"The subject studied the most for is subject "<<i+1<<endl;

    }
}
    int main()
    {
       int rows=4;
        cout<<"Input the amount of hours you study for each subject"<<endl;

        int arr[rows][5];
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<4; j++)
            {
                cout<<"Input the amount of hours you study for subject "<<i+1<<" on day "<<j+1<<endl;
                cin>> arr[i][j];
            }


        }
        getMost(arr,rows,)
           return 0;
    }
