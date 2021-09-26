#include <iostream>
#include <vector>
//#include "vector_header.h"
using namespace std;

int main()
{
    int intArray[] = {1, 4, 5, 6, 7};

    int size = sizeof(intArray)/sizeof(int);
    vector<int> myVector;
    myVector.resize(4);
    for (int i=1; i<=3; i++)
    {
        myVector.push_back(i);
        myVector[i]=intArray[i+1];

    }
    myVector.resize(10);
    for (int i=1; i<=10; i++)
    {
        myVector.push_back(i);
        myVector[i]=0;;
        cout<<myVector[i]<<endl;
    }

    return 0;
}
