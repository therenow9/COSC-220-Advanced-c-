#include <iostream>
using namespace std;
int countNodes(Node<T> head)
{
    Node<T>* curr=head;
//set curr to head
    int i=1;
    if (head==nullptr)
    {
        return 0;
    }
    else
    {
        i+=countNodes(curr->nextNode)
           //do recursion
           return i;
    }
}
void removeDup(const list<T>& l1, const list<T>& l2, list<T>& l3)
{
    typename list<T>::iterator iter_1 = l1.begin();
    typename list<T>::iterator iter_2 = l2.begin();
    typename list<T>::iterator iter_3 = l3.begin();
    bool dupl = false;
    bool dupl_3 = false;
    //values to keep track of where dupes are
    for (iter_1=l1.begin(); iter_1!=l1.end()iter_1++)
    {
        for (iter_2=l2.begin(); iter_2!=l2.end()iter_2++)
        {
            if(*iter_1==*iter_2)
            {
//if there is a match
                dupl=true;
            }
        }
        if (dupl==false)
        {
            for (iter_3=l3.begin(); iter_3!=l3.end()iter_3++)
            {
                if (*iter_1==*iter_3)
                {
                    //there is a duplicate in 3
                    dupl_3=true;
                    break;
                }
            }
        }
        if (dupl_3==false)
        {
            //if no duplicate in 3
            l3.push_back(*iter_1);
            //add value from 1 to l3
        }
        dupl_3=false;
        dupl=false;
        //reset values
    }
    //do same process for the second list
    for (iter_2=l2.begin(); iter_2!=l2.end()iter_2++)
    {
        for (iter_1=l1.begin(); iter_1!=l1.end()iter_1++)
        {
            if(*iter_1==*iter_2)
            {
//if there is a match
                dupl=true;
            }
        }
        if (dupl==false)
        {
            for (iter_3=l3.begin(); iter_3!=l3.end()iter_3++)
            {
                if (*iter_2==*iter_3)
                {
                    //there is a duplicate in 3
                    dupl_3=true;
                    break;
                }
            }
        }
        if (dupl_3==false)
        {
            //if no duplicate in 3
            l3.push_back(*iter_2);
            //add value from 2 to l3
        }
        dupl_3=false;
        dupl=false;
        //reset values
    }
}

int main()
{

    return 0;
}
