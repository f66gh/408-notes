#include<iostream>
using namespace std;

// 建立大根堆
void BuildMaxHeap(int A[], int len){
    // 从后往前建立所有非终端结点 O(n)
    for(int i = len/2; i > 0; i--)
        HeadAdjust(A, i, len);
}

// 以K为子根的子树调整为大根堆 O(1)
void HeadAdjust(int A[], int k, int len){
    A[0] = A[k];
    for(int i = 2 * k; i <= len; i *= 2){
        if(i < len && A[i] < A[i + 1]) // 找到子节点中最大的
            i++;
        if(A[0] >= A[i]) break;
        else { // 交换结点
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

// 堆排序的完整逻辑
void HeapSort(int A[], int len){
    BuildMaxHeap(A, len);
    for(int i = len; i > 1; i--){
        // n-1趟交换和建堆过程, O(nlogn)
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i - 1);
    }
}