#include <iostream>
#include <vector>

using namespace std;
void print_vector(vector<int> vect)
{
    for (int i=0; i<vect.size(); i++)
    {
//display elements of vect
        cout<<vect.at(i)<<" ";
    }
    cout<<endl;
}

int main()
{
//declare vector

    int elems=7;

    vector <int> vect_1(elems,10);
//create a vector of size elems all of equal to size 10
    vector <int> vect_2(vect_1.begin(),vect_1.end());
//iterate through first vect
    vector <int>vect_3(vect_1);
//copies vector 1
    vect_1.push_back(15);
//adds an 8th element of 15
    vect_1.at(4)=9;
//sets 4th element equal to 9
    print_vector(vect_1);


    return 0;
}


