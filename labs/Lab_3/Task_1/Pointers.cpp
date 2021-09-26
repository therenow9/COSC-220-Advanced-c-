/*
  Pointers.cpp
  COSC-220 Lab 9
  Based on a lab designed by Thomas Horseman

  Thomas Anastasio
  Created: April 8, 2001
  Current: March 20, 2003
  Jeremy Scheuerman
*/

#include <iostream>
#include <stddef.h>     // for NULL definition
#include <iomanip>

int main()
{
    using namespace std;

    int int1 = 1, int2 = 2, int3 = 3;
    double dub1 = 1.0, dub2 = 2.0, dub3 = 3.0;
    float flt1 = 1.0f;
    char chr1 = 'a', chr2 = 'b';

    //////////////////////////////////////////////////////////////////
    // 1. Experiment with storage sizes and addresses of various data
    // types.
    //////////////////////////////////////////////////////////////////
    //  A.  Add statements to print the addresses of each of the 9
    //  variables declared above and record the addresses.

    //  B.  Add statements to print the sizes (in bytes) of each of the
    //  9 variables  (use the sizeof operator).
    //  C.  Add statements to print the sizes of the addresses of the 9
    //  variables (again, use the sizeof operator).

    //  Write your code here:

    cout<<"Adressess"<<endl
        <<"int 1: "<<&int1<<endl
        <<"int 2: "<<&int2<<endl
        <<"int 3: "<<&int3<<endl
        <<"dub 1: "<<&dub1<<endl
        <<"dub 2: "<<&dub2<<endl
        <<"dub 3: "<<&dub3<<endl
        <<"flt 1: "<<&flt1<<endl
        <<"chr 1: "<<&chr1<<endl
        <<"chr 2: "<<&chr2<<endl
        <<endl;

    cout<<"Sizes"<<endl
        <<"int 1: "<<sizeof(int1)<<endl
        <<"int 2: "<<sizeof(int2)<<endl
        <<"int 3: "<<sizeof(int3)<<endl
        <<"dub 1: "<<sizeof(dub1)<<endl
        <<"dub 2: "<<sizeof(dub2)<<endl
        <<"dub 3: "<<sizeof(dub3)<<endl
        <<"flt 1: "<<sizeof(flt1)<<endl
        <<"chr 1: "<<sizeof(chr1)<<endl
        <<"chr 2: "<<sizeof(chr2)<<endl
        <<endl;

    cout<<"Sizes of addressess"<<endl
        <<"int 1: "<<sizeof(&int1)<<endl
        <<"int 2: "<<sizeof(&int2)<<endl
        <<"int 3: "<<sizeof(&int3)<<endl
        <<"dub 1: "<<sizeof(&dub1)<<endl
        <<"dub 2: "<<sizeof(&dub2)<<endl
        <<"dub 3: "<<sizeof(&dub3)<<endl
        <<"flt 1: "<<sizeof(&flt1)<<endl
        <<"chr 1: "<<sizeof(&chr1)<<endl
        <<"chr 2: "<<sizeof(&chr2)<<endl
        <<endl;






    cout << "-----------------------------------------" << endl << endl;

    // Record your results here:
    //
    //  Variable  Size   Address   Address-Size
    //   int1       4    0x61ff0c       4
    //   int2       4    0x61ff08       4
    //   int3       4    0x61ff04       4
    //   dub1       8    0x61fef8       4
    //   dub2       8    0x61fef0       4
    //   dub3       8    0x61fee8       4
    //   flt1       4    0x61fee4       4
    //   chr1       1    a              4
    //   chr2       1    ba             4


    // How many bytes of storage is allocated for each data type?  How
    // many bytes is allocated for each pointer (address). Notice that
    // the data types are not necessarily the same size, but the
    // pointers are.
    //4 for integers 8 for double 4 for float 1 for char
    // Did the address of the char variables print as you expected?  If
    // not, why not? no i thought it would be a normal memory address
    //You can force the printed output to be
    // interpreted as a pointer by coercing it (casting) to void* like
    // this:
    //    cout << (void *) &chr1;
    //
    // Run the program again, using the coercion for the char
    // pointers. Record your data.

    // Write your modified code here
    cout << "chr1: " << (void*)&chr1 << endl << "chr2: "
         <<(void*)&chr2 << endl << endl
         << "chr1: " << sizeof((void*)&chr1) << endl
         << "chr2: " << sizeof((void*)&chr2) << endl;

    cout << "-----------------------------------------" << endl << endl;


    // Record your results here:
    //
    //  Variable  Size   Address   Address-Size
    //     chr1     1    0x61fee3        4
    //     chr      1    0x61fee2        4

    //////////////////////////////////////////////////////////////////
    // 2. Experiment with pointer variables.
    //////////////////////////////////////////////////////////////////
    //   A. Declare pointer vaiables intPtr1, intPtr2, intPtr3, dubPtr1,
    //   dubPtr2, dubPtr3, fltPtr1, chrPtr1, and chrPtr2 so that they
    //   can be used to point to the  appropriate variables.  Assign the
    //   address of the appropriate variable to them and print their
    //   values.  (The char pointers will have to be coerced as before
    //   for printing).

    //  Write your code here:
    int *intPtr1 = &int1, *intPtr2 = &int2, *intPtr3 = &int3;
    double *dubPtr1 = &dub1, *dubPtr2 = &dub2, *dubPtr3 = &dub3;
    float *fltPtr1 = &flt1;
    char *chrPtr1 = &chr1, *chrPtr2 = &chr2;

    cout << "-----------------------------------------" << endl << endl;

    cout <<"Pointer values"<<endl
         << "intPtr 1: " << intPtr1 << endl
         << "intPtr 2: " << intPtr2 << endl
         << "intPtr 3: " << intPtr3 << endl
         << "dubPtr 1: " << dubPtr1 << endl
         << "dubPtr 2: " << dubPtr2 << endl
         << "dubPtr 3: " << dubPtr3 << endl
         << "fltPtr 1: " << fltPtr1 << endl
         << "chrPtr 1: " << (void*)chrPtr1 << endl
         << "chrPtr 2: " << (void*)chrPtr2 << endl;

    //  Report your results here:
    //
    //   Pointer  Printed
    //  Variable   Value
    //   intPtr1  0x61fee8
    //   intPtr2  0x61fee8
    //   intPtr3  0x61fee0
    //   dubPtr1  0x61fed8
    //   dubPtr2  0x61fec0
    //   dubPtr3  0x61fec8
    //   fltPtr1  0x61fec4
    //   chrPtr1  0x61fec3
    //   chrPtr2  0x61fec2

    // How do the values of the pointers compare to the values of the
    // addresses you got in the previous experiment?

    //they are the memory addresses of the values
    //
    //
    //

    //////////////////////////////////////////////////////////////////
    //  3. Experiments with NULL pointers and with dereferencing
    //////////////////////////////////////////////////////////////////
    //   A. Assign NULL to fltPtr1, then print the value of fltPtr1.
    //   B. Accessing the storage locations through the relevant
    //   pointers, assign the following values and print them.
    //       int1  12
    //       int2  22
    //       dub1  10.1
    //       dub2  20.2
    //       flt1  30.3

    // Write your code here:
    //fltPtr1=nullptr;
    //cout<<"fltptr1 (null): "<<fltPtr1<<endl;
    *intPtr1 = 12;
    *intPtr2 = 22;
    *dubPtr1 = 10.1;
    *dubPtr2 = 20.2;
    *fltPtr1 = 30.3;


    cout<<"Dereference test"<<endl;
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;
    cout << "dub1: " << dub1 << endl;
    cout << "dub2: " << dub2 << endl;
    cout << "flt1: " << flt1 << endl;

    // Your program should have terminated with a run-time error.
    // What error was reported?
    //
    //Process returned -1073741819
    //
    // Why did it occur?
    //tried to access a nonexistent place in memory
    //

    //   C.  Fix the problem and repeat.

    // Write your code here:


    cout << "-----------------------------------------" << endl << endl;

    //////////////////////////////////////////////////////////////////
    //  4. Experiments with pointer arithmetic
    //////////////////////////////////////////////////////////////////
    //    A.  Print the values of intPtr2, (intPtr2+1) and
    //    (intPtr2-1). Did you get what you expected?
    //No did not get what i expected

    // Write your code here:
    cout<<"Test of ptr and + and - 1"<<endl
        << "intPtr1: " << *intPtr1 << endl
        << "intPtr2 + 1: " << *(intPtr2 + 1) << endl
        << "intPtr - 1:" << *(intPtr2-1) << endl << endl;

    // Write your explanation here:
    //When adding to it it seemed to not do anything
    //however when subtracting the value changed to 3
    //
    //
    //
    //


    //   B. Print the value of intPtr1.
    //   C. Use the increment operator to increment intPtr1.
    //   D. Print the value of intPtr1 again.
    //   E. Print the value of the memory location pointed to by
    //   intPtr1.  Explain what is happening.

    // Write your code here:
    cout<<"Incrementer test"<<endl
        << "intPtr1: " << *intPtr1 << endl;
    intPtr1++;
    cout << "intPtr1: " << *intPtr1 << endl
         << "intPtr1: " << intPtr1 << endl;

    // Write your explanation here.
    //the first is set to 12
    //the second looks like the incremntation didnt go as i thought
    //and the 3rd is a memory address
    //

    cout << "-----------------------------------------" << endl << endl;


    //////////////////////////////////////////////////////////////////
    //  5. Experiments with dynamic allocation
    //////////////////////////////////////////////////////////////////
    //   A.  Use the new operator to dynamically allocate an integer.
    //   B.  Assign the number 6000 to the new location.
    //   C.  Print the address of this new location.
    //   D.  Print the value stored in the new location.
    //   E.  Comment on the address of the new location compared to the
    //   addresses seen in part 2.

    //  Write your code here:

    intPtr1 = new int;
    *intPtr1 = 6000;
    cout <<"test with dynamic allocation"<<endl<<"New Address: "<< intPtr1 << endl
         <<"Pointer Value:"<< *intPtr1 << endl;



    //  Write your results and comments here:
    //
    //  new location address =0xf770d0
    //  contents of new location =appears to be a new location each time

    //  Comment:
    //

    //  F.  Use the new operator to allocate an array of size 10 of
    //  doubles.  Fill the array with 10.0,20.0,...100.0 and print the array.
    double *arr=new double[10];
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;
    arr[5]=60;
    arr[6]=70;
    arr[7]=80;
    arr[8]=90;
    arr[9]=100;
    cout<<"Array of doubles:"<<endl;
    for (int i=0;i<10;i++){
    cout<<fixed<<setprecision(2)<<arr[i]<<endl;
    }

    // Write your code here:

    return 0;
}
