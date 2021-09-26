#include <stack>
#include <iostream>

using namespace std;

template <typename T>
void changeValue(stack<T> &s, int i, T newValue)
{
    stack<T> temp;
    //whatever is on main stack is getting pushed into the stcack
    for (int j = 1; j < i; j++)
    {
        temp.push(s.top());
        //push in inserting something into the top value
        s.pop();
        //to move to next value in stack
    }
    s.top() = newValue;
    //set s .top to new value
    while(!temp.empty())
    {
        s.push(temp.top());
        //push popped values back into the array
        temp.pop();
        // pop is deleteing the top element
    }

}


int main()
{
    stack<int> intStack;

    for (int i = 1; i <= 100; i++)
        intStack.push(i);
        //set stack equal nums from 1 to 100

    intStack.top() = 200;
    //set top = to 200

    changeValue(intStack, 100, 0);

    while(!intStack.empty())
    {
        cout << intStack.top() << " ";
        intStack.pop();
        //print the top element of stack then delete it the nm ove onto the next one
    }



    return 0;
}
