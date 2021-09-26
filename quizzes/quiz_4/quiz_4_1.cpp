#include <iostream>
#include <vector>
//#include "vector_header.h"
using namespace std;

int main()
{
    vector <int> intV;
    //declare vector
    for (int i=1;i<=5;i++){
        intV.push_back(i);
    }
    intV[1]=1;
    for(int i=1;i<=5;i++){

        intV[i]=100;
        cout<<intV[i]<<endl;
    }
    intV.push_back(0);
    cout<<intV[5]<<endl;

    return 0;
}
