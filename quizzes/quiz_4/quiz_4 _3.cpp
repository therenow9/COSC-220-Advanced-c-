#include <iostream>
#include <vector>
//#include "vector_header.h"
using namespace std;

int main()
{

    vector<char> mycharVector;
    mycharVector.resize(2);
    mycharVector[1]='A';
    mycharVector[2]='B';
    cout<<mycharVector[1]<<endl;
    cout<<mycharVector[2]<<endl;
    return 0;
}
