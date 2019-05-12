#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include<iostream>
using namespace std;

class SortsAlgo{
    public:
    SortsAlgo(){}
    ~SortsAlgo(){}

    void insertSortWithGuard(vector<int> &arr);

    void shellSort(vector<int> &arr);

    void bubbleSort(vector<int> &arr);

    void quickSort(vector<int> &arr);
    void quickSortImp(vector<int> &arr,int low, int high);
    int partition(vector<int> &arr,int low, int high);

    void simpleSelectSort(vector<int> &arr);

    void heapSort(vector<int> &arr);
    void buildMaxHeap(vector<int> &arr, int len);
    void adjustDown(vector<int> &arr,int k, int len);
    void adjustUp(vector<int> &arr,int k, int len);

    void mergeSort(vector<int> &arr);
    void mergeSortImp(vector<int> &arr,int low, int high);
    void merge(vector<int> &arr,int low, int mid, int high);

};

#endif