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
    for (int i=0; i<v.size(); i++)
    {
        unsigned var=seqVectSearch(v,i+1,v.size(),v[i]);
        if (var!=v.size())
        {
                v.erase(v.begin()+var);
                //removes the index of the duplicated vector
                v.erase( v.begin()+i);
                //revmoves the address of the index  that you want to remove
                i--;
                //decrease size
        }
    }
}


template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first,
                       unsigned last, const T& target)
//search algortihim to go thorugh the vector searching for certain elmeents
{
    {
        unsigned index = first;
        //declare head as first
        while(index<last)
        {
                        //while the vector is not empty
            if(v[index]== target)
                //if the index is targeted return it
            {
                return index;
            }
            index++;
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
