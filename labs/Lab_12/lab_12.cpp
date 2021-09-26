#include "dynClass.h"

int main()
{
    dynClass test1(14,26);
//initial constructor for test 1
    dynClass test2(test1);
//copy constructor for second object
    dynClass test3 (15,17);
    test3=test1;
//operator overload for 3rd object

//all destructors called at the end

    return 0;
}
