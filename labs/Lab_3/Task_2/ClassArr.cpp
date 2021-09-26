/*
  ClassArr.cpp
  Dynamically allocated array of ThreeDimPt objects.
  Lab 10, COSC-220
  Created: April 7, 2001
  Current: November 5, 2001
*/

#include "ThreeDimPt.h"

#include <iostream>

using namespace std;


/* GetNumbPts
 * Prompts for and returns an int value.
 * Enforces the value being positive.
 */
int GetNumbPts();

/* MakeThreeDimPtArray
 * Constructs an array of ThreeDimPt objects.
 * Array is of length size.
 * Returns a pointer to the first element of the
 * array.
 */
ThreeDimPt * MakeThreeDimPtArray(int size);
// Uncomment and define the function.
ThreeDimPt * MakeThreeDimPtArray(int size)
{
// Write your code here
    ThreeDimPt*ptr=nullptr;
    ptr=new ThreeDimPt[size];
    return ptr;
}

int main()
{
    int nPts = GetNumbPts();
    int i;

    ThreeDimPt * ptArr;  // array of ThreeDimPt objects

    ptArr = MakeThreeDimPtArray(nPts);

    // Set the x, y, and z values of each ThreeDimPt in the
    // array as x = i,  y = 2 * i,  z = 3 * i;
    //
    // Write your code here:

    for (i=0; i<nPts; i++)
    {
        //define values
        ptArr[i].SetX(i);
        ptArr[i].SetY(2*i);
        ptArr[i].SetZ(3*i);
    }

    // Print the array.
    //
    // Write your code here:
    for (int j=0; j<nPts; j++)
    {
        cout<<ptArr[j]<<endl;
    }
    return 0;
}



int GetNumbPts()
{

    int n;

    cout << "How many points? ";
    cin >> n;

    while (n < 0)
    {
        cout << "Number can't be negative" << endl;
        cout << "How many points? ";
        cin >> n;
    }

    return n;
}
