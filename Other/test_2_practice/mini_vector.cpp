#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>intV(5,1);
    //5 slots all with 1 in them
    for (int i=0;i<intV.size();i++)
        cout<<intV[i];



}
