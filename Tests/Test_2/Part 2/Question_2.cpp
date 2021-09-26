#include <iostream>
#include <stack>
#include <list>
template <typename T>
bool getNthElement(std::stack<T> q, T& value, int n)

{
    if(n > q.size()||q.empty())
    {
        //if n is greater than the size of the stack or it is empty

        return false;
    }
    else
    {
        std::stack<T> temp_stack;
        for (int i = 1; i < n; i++)
        {
            temp_stack.push(q.top());
            q.pop();
        }
        value = q.top();
        //set equal to the top of the stack
        while(!temp_stack.empty())
            //while there are still items in the stack
        {
            q.push(temp_stack.top());
            //push forward
            temp_stack.pop();
            //pop off the top
        }
    }
}
template <typename T>

void addNext(std::list<T> & li)

{
    std::list<T> temp_list;
    //create temp list to hold it int
    typename std::list<T>::iterator I, prev_I;
    prev_I = li.begin();
    //set previous iterator to beginning of the list

    for(I = li.begin()+1; I != li.end(); I++)
    {
        prev_I = I--;
        temp_list.push_back(*I+I);
    }
    li = temp_list;
    //set list equal back to temp

}
template <typename T>
void duplList(Node<T>* & front)
{
    Node<T>* curr = front;
    Node<T>* prev = nullptr;
    //declare current and previous
    while(currNode != nullptr)
    {
        Node<T>* duplicate = new Node<T>;
        duplicate->value = curr->value;
        duplicate->next = curr;
        //declare duplicate and assign
        if(prev != nullptr
    {
        prev ->next = dupe;
    }
}
prev = curr;
//set previous back to current
curr = curr->next;
//set current to = the next value in the sequence

}
int main()
{

    return 0;
}
