#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> myCharVector;

    myCharVector.push_back('A');
    myCharVector.push_back('B');

    for (int i = 0; i < myCharVector.size(); i++)
        cout << myCharVector[i] << " ";
    return 0;
}
