#include <queue>
#include <iostream>

using namespace std;
//with queues you can only insert from the back but delete from the top
//uses front and back instead of top
template <typename T>
void changeValue(queue<T> &q, int i, T newValue)
{
    queue<T> temp;
    //whatever is on main stack is getting pushed into the stcack
    for (int j = 1; j < i; j++)
    {
        temp.push(q.front());
        //push in inserting something into the front value
        q.pop();
        //to move to next value in stack
    }
    q.front() = newValue;
    //set s .top to new value
    while(!q.empty()){
    temp.push(q.front());
    q.pop();

    }
    while(!temp.empty())
    {
        q.push(temp.front());
        //push popped values back into the array
        temp.pop();
        // pop is deleting the front element
    }

}


int main()
{
    queue<int> intQueue;

    for (int i = 1; i <= 100; i++)
        intQueue.push(i);
        //set stack equal nums from 1 to 100

    intQueue.front() = 200;
    //set top = to 200

    changeValue(intQueue, 100, 0);

    while(!intQueue.empty())
    {
        cout << intQueue.front() << " ";
        intQueue.pop();
        //print the top element of stack then delete it the nm ove onto the next one
    }



    return 0;
}

