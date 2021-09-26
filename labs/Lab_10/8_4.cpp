
//Jeremy Scheuerman

#include <iostream>
void displayArray(int array[], int elems);
void bubbleSortArray(int array[],int newArray[], int elems);
int binarySearch(int array[], int numElems, int value);
double findMean(int array[],int arraySorted[],int numElems,int value);
using namespace std;
int main()
{
    int value;
    int found;
    double mean;
    int num_el=51;
    while (num_el<1||num_el>50)
    {
        cout << "Enter the number of integers in the array (1-50)"<<endl;
        cin>>num_el;
    }
     int array_Sorted[num_el];
    int num_array[num_el];

    for (int i=0; i<num_el; i++)
    {
        cout<<"Enter element "<<(i+1)<<" of the array"<<endl;
        cin>>num_array[i];

    }
    bubbleSortArray(num_array,array_Sorted,num_el);
    cout<<"Please enter the value you would like to search for"<<endl;
    cin>>value;
    cout<<value<<endl;
    mean=findMean(num_array,array_Sorted,num_el,value);
    cout<<"The mean of the array is "<<mean<<endl;
    return 0;
}
void displayArray(int array[], int elems)	// function heading
{
    //displays the array
    for (int count = 0; count < elems; count++)
        cout << array[count] << "	" << endl;
}

//******************************************************************
//	bubbleSortArray
//
//  task:	  to sort values of an array in ascending order
//  data in:  the array, the array size
//  data out: the sorted array
//
//******************************************************************

void bubbleSortArray(int array[],int newArray[], int elems)
{
    for (int i=0;i<elems;i++){
        newArray[i]=array[i];
    }
    bool swap;
    int temp;
    int bottom = elems - 1;	// bottom indicates the end part of the
    // array where the largest values have

    // settled in order
    do
    {
        swap = false;

        for (int count = 0; count < bottom; count++)
        {
            if (newArray[count] > newArray[count + 1])
            {
                // the next three lines do a swap
                temp = newArray[count];
                newArray[count] = newArray[count + 1];
                newArray[count + 1] = temp;

                swap = true; // indicates that a swap occurred
            }
        }

        bottom--;	// bottom is decremented by 1 since each pass through
        // the array adds one more value that is set in order

    }
    while (swap != false);
    // loop repeats until a pass through the array with
    // no swaps occurs
    cout<<endl;
}

int binarySearch(int array[], int numElems, int value)	// function heading
{
    int first = 0;				// First element of list
    int last = numElems - 1;	// last element of the list
    int middle;					// variable containing the current
    // middle value of the list

    while (first <= last)
    {
        middle = first + (last - first) / 2;

        if (array[middle] == value)
            return middle;		// if value is in the middle, we are done

        else if (array[middle]<value)
            first = middle + 1;	// toss out the second remaining half of

        else
            last = middle - 1;	// toss out the first remaining half of
        // the array and search the second
    }

    return -1;	// indicates that value is not in the array
}
double findMean(int array[],int arraySorted[],int numElems,int value)
{
    int found;
    double mean=0;
    cout<<"The array size is "<<numElems<<endl;
    cout<<"The array as entered by the user is :"<<endl;
    displayArray(array,numElems);
    cout<<"The sorted Array is:"<<endl;
    displayArray(arraySorted,numElems);
    found=binarySearch(arraySorted,numElems,value);
    if (found == -1)
    {
        cout << "The value " << value << " is not in the array" << endl;
    }
    else

    {
        cout << "The value " << value << " is in position number "
             << found + 1 << " of the sorted array list" << endl;
    }
    for (int i=0; i<numElems; i++)
    {

        mean+=arraySorted[i];
    }
    mean=mean/numElems;
    return mean;

}
