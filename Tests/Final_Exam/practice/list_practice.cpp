#include <iostream>
#include <list>

using namespace std;

void print_list(list <int> my_list)
{
//function to to print the list
    list <int>::iterator it;
//create iterator to go through the list
    for (it=my_list.begin(); it!=my_list.end(); ++it)
        //setup iterator
    {
        cout<<*it<<" ";
        //loop through iterator to print list
    }
    cout<<endl;
}

int main()
{
    list <int> my_list;
    //declare new list

    my_list.push_front(34);
    //adds a new value to the front of the list
    my_list.push_back(87);
    //adds a new value to the back of the list
    my_list.push_back(76);
    my_list.push_back(90);
    my_list.push_back(56);
    cout<<my_list.front()<<endl;
    //print the first value in the list
    cout<<my_list.back()<<endl;
    //print the value at the end of the list
    my_list.pop_back();
    //removes a value from the end of the list
    my_list.pop_front();
    //removes a value from the front of the list
    //cout front and back again after removing one from each
        cout<<my_list.front()<<endl;
    //print the first value in the list
    cout<<my_list.back()<<endl;
    //print the value at the end of the list
    my_list.push_front(57);
    my_list.push_back(65);
    my_list.push_front(32);
    my_list.push_back(23);
    print_list(my_list);
    //use print list function
    return 0;
}
