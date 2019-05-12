#include<iostream>
#include<vector>
#include "sorts.h"

using namespace std;

//带哨兵的直接插入排序,  哨兵也可以改为临时变量，哨兵还挺蠢的 升序
void SortsAlgo::insertSortWithGuard(vector<int>& arr){
    int size = arr.size();
    if(size==0){
        return;
    }
    //复制一份，给哨兵留个位置
    vector<int> a;
    a.push_back(0);
    a.insert(a.end(), arr.begin(), arr.end());
    int i = 0, j = 0; //定义初始化而已

    //索引从2开始是因为 算法要求从a[2]~a[n] 插入到前面已排序的序列中，
    //a[1]单个元素默认是已排序
    for(int i = 2; i<=size; i++){
        if(a[i] < a[i-1]){
            a[0] = a[i];//哨兵 又是暂存
            for(j = i-1; a[0] < a[j];--j){
                //找正确位置的时候，把元素往后挪，以便腾出位置
                a[j+1] = a[j]; 
            }
            //找到正确的插入位置（当前的j后面), 则插入当前的判断元素a[i]
            a[j+1] = a[0]; 
        }
    }

    //删除哨兵位置，返回
    for(int i = 1; i < a.size();i++){
        arr[i-1] = a[i];
    }
    return;
}

//希尔排序 升序
void SortsAlgo::shellSort(vector<int>& a){
    int size = a.size();
    if(size==0){
        return;
    }  
    int tmp = 0; //暂存 可以用a[0]做暂存，不过a[0]必须是非数组元素，所以蠢
    int dk, i,j;
    //dk =1 就是直接插入排序
    for (dk = size/2; dk >= 1; dk = dk/2){
        for(i = dk; i < size; i++){
            if(a[i] < a[i-dk]){
                tmp = a[i]; //暂存当前元素
                for(j = i-dk; j>=0 && tmp < a[j]; j= j-dk){
                    a[j + dk] = a[j];
                }

                a[j+dk] = tmp;
            }
        }
    }
    return;
}


//冒泡排序 升序
void SortsAlgo::bubbleSort(vector<int>& a){
    int size = a.size();
    if(size==0){
        return;
    } 

    int swaptmp; //交换时用的临时变量

    //最多n-1趟排序
    for(int i = 0; i< size-1; i++){
        bool hasSwap = false;

        //从后往前判断, 每趟选出最小的元素 放到前面，所以i在增长
        for(int j = size -1; j > i; j--){
            if(a[j] < a[j-1]){
                swaptmp = a[j];
                a[j] = a[j-1];
                a[j-1] = swaptmp;
                hasSwap = true;
            }
        }
        //本趟没有交换，说明已经排序好了
        if(!hasSwap){
            return;
        }
    }
}

//快速排序 升序
void SortsAlgo::quickSort(vector<int> &a){
    int size = a.size();
    if(size==0){
        return;
    }
    int low = 0;
    int high = size-1;
    quickSortImp(a, low, high);
}

//快速排序 具体实现
void SortsAlgo::quickSortImp(vector<int> &arr,int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high); 
        quickSortImp(arr, low, pivot -1);
        quickSortImp(arr, pivot+1, high);
    }
}

//快速排序 划分函数 升序
int SortsAlgo::partition(vector<int> &a,int low, int high){
    int pivot = a[low]; //优化点就是在这里了 首次划分选择枢轴点
    while (low < high)
    {
        while(low < high && a[high] >= pivot)   --high;
        a[low] = a[high];

        while(low < high && a[low]<=pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

//简单选择排序
void SortsAlgo::simpleSelectSort(vector<int> &a){
    int size = a.size();
    if(size==0){
        return;
    }
    int tmp; //交换时的临时变量
    for(int i = 0;i <size -1;i++){
        int min = i;
        for(int j = i+1; j<size;j++){
            if(a[j] < a[min]) min = j;
        }
        if(min != i){
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

//堆排序
void SortsAlgo::heapSort(vector<int> &arr){
    int size = arr.size();
    if(size==0){
        return;
    }
    //复制一份，给a[0]留个位置
    vector<int> a;
    a.push_back(0);
    a.insert(a.end(), arr.begin(), arr.end());

    buildMaxHeap(a, size);
    int tmp;

    //每次输出最大的到数组尾部，结果是升序
    for(int i = size; i > 1; i--){
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        adjustDown(a, 1, i-1);
    }

    //删除暂存位置，返回
    for(int i = 1; i < a.size();i++){
        arr[i-1] = a[i];
    }
}

//构建一个大根堆
void SortsAlgo:: buildMaxHeap(vector<int> &a, int len){
    for(int i = len/2; i > 0; i--){ 
        //i>0 是因为a[0]不是堆元素，暂存元素
        adjustDown(a, i, len);
    }
}

//堆排序 向下调整，删除元素 a[0] 暂存用
void SortsAlgo::adjustDown(vector<int> &a, int k, int len){
    a[0] = a[k];
    //从元素k的左儿子开始判断 循环结束条件注意
    for(int i = 2*k; i <= len; i = i*2){
        //左右儿子谁大选谁
        if(i < len && a[i] < a[i+1]){
            i++;
        }
        //已经满足条件，结束
        if(a[0] >= a[i]) {
            break;
        }else{
            a[k] = a[i]; //儿子节点上移到父节点,儿子节点位置自己不担心会被其他填对
            k = i; //继续往下继续判断
        }
    }
    a[k] = a[0]; //原元素a[k] 放到正确的位置
}

//堆排序 向上调整，插入元素 a[0] 暂存用
void SortsAlgo::adjustUp(vector<int> &a,int k, int len){
    a[0] = a[k];
    int i = k/2; //从其双亲节点开始判断
    //i = i/2 代表一直向上
    //结束条件，只有满足大根堆时停止
    for(i = k/2; i>0 && a[i] < a[0]; i = k/2){
        a[k] = a[i]; //父亲节点下移到儿子节点自己，父亲节点不担心，继续向上找合适的
        k = i;//继续向上调整
    }
    a[k] = a[0]; //原元素a[k] 放到正确的位置
}


//归并排序
void SortsAlgo::mergeSort(vector<int> &arr){
    int size = arr.size();
    if(size==0){
        return;
    }
    mergeSortImp(arr, 0, size -1);
}

//归并排序 递归处理
void SortsAlgo::mergeSortImp(vector<int> &a,int low, int high){
    if(low < high){
        int mid = (low + high) /2;
        mergeSortImp(a, low, mid);
        mergeSortImp(a, mid+1, high);
        merge(a,low, mid, high);
    }
}

//归并 两个有序列表部分a[low...mid] a[mid+1...high] 各自有序
void SortsAlgo::merge(vector<int> &a,int low, int mid, int high){
    vector<int> b;
    b.insert(b.end(), a.begin(), a.end());

    int i,j,k;
    for(i = low, j = mid+1, k = i; i<=mid && j<= high; k++){
        if(b[i] < b[j]){
            a[k] = b[i++];
        }else{
            a[k] = b[j++];
        }
    }

    while(i<=mid) a[k++] = b[i++];
    while(j<=high) a[k++] = b[j++];
}   