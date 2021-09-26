#include "sorting_functions.h"
#include <iostream>
#include <algorithm>
#include <vector>

//https://stackoverflow.com/questions/30963204/c-vector-bubble-sort/30963237
void bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}
/* Function to sort a vector using insertion sort*/
//found from stack overflow
void insertionSort (vector<int> data)
{
    int n=data.size();
    int i, j, tmp;

    for (i=1; i<n; i++)
    {
        j=i;
        tmp=data[i];
        while (j>0 && tmp<data[j-1])
        {
            data[j]=data[j-1];
            j--;
        }
        data[j]=tmp;
    }
}
void selectionSort(vector <int> vect)
{
    int vecsize = vect.size() ;
    for (int j = 0; j < vecsize - 1; ++j)
    {

        int min = j;
        for (int i = j+1; i < vecsize; ++i)
        {
            if (vect.at(min) > vect.at(i))
            {
                min = i;
            }

        }
        if (min != j)
            swap(vect.at(j), vect.at(min));
    }
}
void Swap(std::vector<int>& vHeap, std::vector<int>::size_type i, std::vector<int>::size_type j)
{
    if(i == j)
        return;

    int temp;
    temp = vHeap[i];
    vHeap[i] = vHeap[j];
    vHeap[j] = temp;
}
//https://gist.github.com/angelorohit/5858932
void Sift(std::vector<int>& vHeap, const std::vector<int>::size_type heapSize, const std::vector<int>::size_type siftNode)
{
    std::vector<int>::size_type i, j;

    j = siftNode;
    do
    {
        i = j;
        if(((2*i + 1) < heapSize) && vHeap[j] < vHeap[2*i + 1])
            j = 2*i + 1;
        if(((2*i + 2) < heapSize) && vHeap[j] < vHeap[2*i + 2])
            j = 2*i + 2;

        Swap(vHeap, i, j);
    }
    while(i != j);
}

void MakeInitialHeap(std::vector<int>& vHeap)
{
    for(int i = vHeap.size() - 1; i >= 0; --i)
    {
        Sift(vHeap, vHeap.size(), i);
    }
}

void HeapSort(std::vector<int>& vHeap)
{
    MakeInitialHeap(vHeap);
    for(std::vector<int>::size_type i = vHeap.size()-1; i > 0; --i)
    {
        Swap(vHeap, i, 0);
        Sift(vHeap, i, 0);
    }
}
vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         }
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;

   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }

   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);

   return result;
}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
//https://www.thepolyglotdeveloper.com/2019/04/sort-vector-integers-quicksort-algorithm-cpp/
void quicksort(vector<int> &values,int left,int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void radix_sort(std::vector<int>& arr)
{
    int radix = 1;
    // Largest element in unsorted array
    int max = *(std::max_element(arr.begin(), arr.end()));
    while(max / radix)
    {
        // Buckets used for sorting. Each bucket representing a digit.
        std::vector<std::vector<int>> buckets(10, std::vector<int>());
        for(const auto& num : arr)
        {
            int digit = num / radix % 10;
            buckets[digit].push_back(num);
        }
        std::size_t k = 0;
        // Take the elements out of buckets into the array
        for(std::size_t i = 0; i < 10; i++)
        {
            for(std::size_t j = 0; j < buckets[i].size(); j++)
            {
                arr[k] = buckets[i][j];
                k++;
            }
        }
        // Change the place of digit used for sorting
        radix *= 10;
    }

}
void displayVector (vector<int> & vec) {
    for (int i =0 ; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
