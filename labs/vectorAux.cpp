/*
  vectorAux.cpp
  Implementations of template functions
  Cosc-220   Lab 7

  Thomas Anastasio
  Created: February 25, 2003
  Current: March 13, 2003
*/


//////////   THIS CODE IS PROVIDED TO STUDENTS   /////////////



#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void removeDup(std::vector<T> & v)
//removes duplicates from the vector
{
    std::vector <int> my_vector;
    unsigned head;
    unsigned bottom;

    for (int i=0; i<v.size(); i++)
    {
        if(seqVectSearch(v,i,bottom,i)!=v[head])
            //if none are equal to the top
        {
            my_vector.push_back(seqVectSearch(v,i,bottom,i));
            //push back vector sequence and search
        }
    }
}


template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first,
                       unsigned last, const T& target)
{
    {
        unsigned head = first;
        //declare head as first
        while((v[head] != target) && (v[head] <= last))
            //while target vector is not first
        {
            if((head) == target)
                //if head is targeted return it
            {
                return head;
            }
            head++;
        }
        return last;
    }
// return last if target not found
}

template <typename T>
void writeVector(const std::vector<T> & v)
{
    unsigned i;
    unsigned n = v.size();

    for (i = 0; i < n; i++)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
}
