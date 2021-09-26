#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    list<int> intArr(5);
    list<int>::iterator iter;
    iter = intArr.begin();
    //setting iterator = to the memory address of the first value of intarr
    for(int i = 0; i<intArr.size(); i++)
    {
        *iter = (i+1)*10;
        //to set all equal to 10
        iter++;
        //goes to next element but dont use deference
    }
//iter=iter+10

    list<int> intList(intArr.begin(), intArr.end());

    for(iter = intList.begin(); iter!=intList.end(); iter++)
        intList.insert(iter, *iter);
        //inserting iter pointer into iter

    /*
    iter = intList.begin();
    int n = intList.size();
    //as you insert the size changes so this is the reasoning for this
    for(int i = 0; i< n; i++)
    {
        intList.insert(iter++, (i+1)*10);
    }
    */

    iter = intList.begin();
    for(int i = 0; i< intList.size(); i++)
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;

    iter = intList.begin();
    for(int i = 0; i< intList.size(); i++)
    {
        if(i % 2 == 0)
            intList.erase(iter++);
        iter++;
    }

    iter = intList.begin();
    for(int i = 0; i< intList.size(); i++)
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;

    return 0;
}
