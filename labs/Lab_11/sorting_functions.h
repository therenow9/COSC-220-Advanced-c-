#ifndef sorting_functions
#define sorting_functions
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a);

void insertionSort (vector<int> data);

void selectionSort(vector <int> vect);

void Swap(std::vector<int>& vHeap, std::vector<int>::size_type i, std::vector<int>::size_type j);

void Sift(std::vector<int>& vHeap, const std::vector<int>::size_type heapSize, const std::vector<int>::size_type siftNode);

void MakeInitialHeap(std::vector<int>& vHeap);

void HeapSort(std::vector<int>& vHeap);

vector<int> merge(vector<int> left, vector<int> right);

vector<int> mergeSort(vector<int> m);

void quicksort(vector<int> &values,int left, int right);

int partition(vector<int> &values, int left, int right);

void radix_sort(std::vector<int>& arr);

void displayVector(vector <int> &v);

//#include "sorting_functions.cpp"
#endif
