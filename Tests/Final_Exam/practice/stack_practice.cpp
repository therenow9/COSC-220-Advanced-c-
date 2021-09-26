#include <iostream>
#include <stack>


using namespace std;
void print_stack(stack <int> my_stack)
{
    stack <int>temp=my_stack;
//create temp variable because of pass by reference
    while(temp.empty()==false)
    {
//while the stack isnt empty
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}
//create stack
int main()
{
    stack<int> my_stack;
    my_stack.push(21);
//adds 21 to stack increases size by 1
    my_stack.push(7);
//adds 7 to the stack also increasing the size
//7 is now on top

    cout<<my_stack.top()<<endl;
    //cout top of the stack
    cout<<my_stack.empty()<<endl;
    //is the stack empty? should return false or 0 since there are 2 elements in it
    my_stack.pop();
    //removed the top element (7) from the top of the stack
    my_stack.push(18);
    my_stack.push(11);
    //add these 2 elements on top
    cout<<my_stack.size()<<endl;
    //output the size (should be 3)
    cout<<my_stack.top()<<endl<<endl;
    //outputs the top should be 11
    my_stack.push(19);
    my_stack.push(61);
    my_stack.push(76);
    my_stack.push(35);
    //push a bunch of elements on top of the stack
    print_stack(my_stack);

    return 0;
}

