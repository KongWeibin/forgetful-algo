#include<iostream>
#include "sorts.h"
#include<vector>
#include<string>

using namespace std;

void myPrintVector(string algoName, vector<int> &arr){
   cout<< algoName <<" sorted:"<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //初始化一个数组
    int myints[] = {155,-100,23,1,0,4,34,21,17,2019};
    vector<int> arr(myints, myints + sizeof(myints) / sizeof(int));

    cout<<"raw array:"<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;

    SortsAlgo sl;

    //插入排序之 测试简单直接插入排序
    vector<int> arr1 = arr;
    sl.insertSortWithGuard(arr1);
    myPrintVector("insertSortWithGuard", arr1);

    //插入排序之 测试希尔排序
    vector<int> arr2 = arr;
    sl.shellSort(arr2);
    myPrintVector("shellSort", arr2);

    //交换排序之 冒泡排序
    vector<int> arr3 = arr;
    sl.shellSort(arr3);
    myPrintVector("bubbleSort", arr3);

    //交换排序之  快速排序
    vector<int> arr4 = arr;
    sl.quickSort(arr4);
    myPrintVector("quickSort", arr4);

    //选择排序之 简单选择排序
    vector<int> arr5 = arr;
    sl.simpleSelectSort(arr5);
    myPrintVector("simpleSelectSort", arr5);

    //选择排序之 堆排序
    vector<int> arr6 = arr;
    sl.heapSort(arr6);
    myPrintVector("heapSort", arr6);

    //归并排序
    vector<int> arr7 = arr;
    sl.mergeSort(arr7);
    myPrintVector("mergeSort", arr7);
    return 0;
}

