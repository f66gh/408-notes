#include<iostream>
using namespace std;

int Binary_Search(SSTable L, int key){
    int low = 0;
    int high = L.length() - 1;
    int mid;
    while(low < high){ // 注意-1+1
        mid = (low + high) / 2;
        if(key < L[mid]) high = mid - 1;
        if(key > L[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}