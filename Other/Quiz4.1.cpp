#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int intArray[] = {1,4,5,6,7};

    int size = sizeof(intArray)/sizeof(int);

    vector<int> myIntVector(intArray+1, intArray+4);

    myIntVector.push_back(100);

    myIntVector.resize(10, 0);

    for (int i = 0; i < myIntVector.size(); i++)
        cout << myIntVector[i] << " ";
    return 0;
}
