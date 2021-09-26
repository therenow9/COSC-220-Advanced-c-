#include <iostream>
#include <queue>
using namespace std;
void print_queue(queue<int> my_queue)
{
//queues must be popped till empty to be printed, best to do this in a function
    queue <int> temp=my_queue;
    while(temp.empty()==false)
    {
        cout<<temp.front()<<" ";
//print out front
        temp.pop();
//pop one off the top
    }
    cout<<endl;
}
int main()
{
    queue<int> my_queue;
    //declare queue
    my_queue.push(5);
    //adds element to the END of the queue different form stack
    cout<<my_queue.front()<<endl;
    //print top element
    my_queue.push(7);
    //adds 7 to the back of the queue
    cout<<my_queue.front()<<endl;
    //print front element of queue should still be 5
    my_queue.pop();
    //removes element from the front
    cout<<my_queue.front()<<endl<<endl;
    //now the front element should be 7
    my_queue.push(65);
    my_queue.push(89);
    my_queue.push(54);
    my_queue.push(78);
    my_queue.push(23);
    //add a bunch of elements to queue
    print_queue(my_queue);
    //use queue print function
    return 0;
}

