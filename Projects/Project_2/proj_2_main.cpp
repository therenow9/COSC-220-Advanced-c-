#include "auxilary_functions.h"
int main()
{
    char selection = 'y';
    int act;
    int impl;
    int choice;
    //init user input variables+
    do
    {
        //initialize each time to reset them
        miniQueueVT<int> queue_vt;
        miniQueueDA<int> queue_da;
        miniQueueLT<int> queue_lt;
        miniQueueDL<int> queue_dl;
        miniStackVT<int> stack_vt;
        miniStackDA<int> stack_da;
        miniStackLT<int> stack_lt;
        miniStackDL<int> stack_dl;

        choice=get_choice();
        impl=get_implementation();
        act=-1;
        //get choice and implementation
        while (act!=5)
        {
            act = get_actions();
            execute(choice, impl,act, stack_vt, stack_da, stack_lt, stack_dl,
                    queue_vt, queue_da, queue_lt, queue_dl);
        }

        cout << "Repeat with a different implementation?" << endl
             << "Y for yes and N for no" << endl;
        cin >> selection;
        selection=tolower(selection);
        //get lower case for error checking
        cout << endl;

    } while (selection=='y');
}
