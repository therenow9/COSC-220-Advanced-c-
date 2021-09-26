#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> intV(5, 1);
    //create vector with 5 slots all set to 1 when initialized
    for (int i = 0; i < intV.size(); i ++)
        intV[i] = 100;

    intV.back() = 0;
    //set last element to 0
    intV.push_back(100);
    //adds new element onto the end thats a 100
    myintVecotr.erase(myintVector.begin()+1);
    //erases second element then 3rd bcomes second and so on
    myintVector.resize(10,0);
    //resizes the vector and sets all new elements to 0
    //ex: if vecotr has 1 5 6 7 8 it becomes 1 5 6 7 0 0 0 0 0

    my
    cout << intV.back() << endl;
    return 0;
}
