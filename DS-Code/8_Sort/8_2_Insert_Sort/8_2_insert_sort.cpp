#include<iostream>
using namespace std;

/**
 * @brief A是未排序的数组，n是数组长度
 * 插入排序要求从小至大非递减排序
 * 插入排序每次循环把前面i个数据都排好
 * @param A 
 * @param n 
 */
void InsertSort(int A[], int n){
    int i,j;
    for(i = 2; i <=n; i++){ // 依次将A[2]~A[n]插入前面已经排序的序列
        if(A[i] < A[i - 1]){ // 若插入元素已经是最大则直接跳出循环
            A[0] = A[i]; // 哨兵，放在了数组最开始的位置，每次循环不用判断数组是否越界了
            for(j = i - 1; A[0] < A[j]; --j){ // 将前面已经排好的数据依次向后挪
                A[j + 1] = A[j];
            }
            A[j+1] = A[0]; // 复制到正确为止
        }
    }
}
/**
 * 折半插入排序，借助折半查找定位待排序元素的位置
*/
void HalfInsertSort(int A[], int n){
    int i, j ,low, high, mid;
    for(i = 2; i <= n; i++){
        A[0] = A[i];
        low = 1;
        high = i -1;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] > A[0]) high = mid - 1;
            else low = mid -1;
        }
        for(j = i - 1; j >= high + 1; j--){
            // 注意要是待插入元素和Mid所指元素相同则需要插入到最右边
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}