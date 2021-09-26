
#include "sorting_functions.cpp"
#include <ctime>
#include <iomanip>
int main()

{
    int max_elem=500;
    cout<<"Vector Size: "<<max_elem<<endl;
    vector<int> myVector;
    for(int i = 0; i <max_elem ; i++)
    {
        myVector.push_back(rand() % 2000);
    }
    cout<<"Unsorted vector"<<endl;
   // displayVector(myVector);
    //cout<<endl;

    double start = double(clock()) / CLOCKS_PER_SEC;

    // . . . Perform some calculation . . .
    for (int i=0; i<1000; i++)
    {
        bubbleSort(myVector);
    }

    double finish = double(clock()) / CLOCKS_PER_SEC;
     double elapsed = (finish - start)/1000;
    cout<<"Sorted Vector"<<endl;
   // displayVector(myVector);
    cout<<endl<<"Elapsed time: "<<setprecision(6)<<std::fixed<<elapsed;

}
