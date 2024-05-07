#include <iostream>
using namespace std;

// 静态线性表
#define MAXSIZE 10
typedef struct{
    int data[MAXSIZE];
    int length;
}SqList_Static;

// 动态线性表
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SqList_Dynamic;

//初始化一个顺序表
void InitList(SqList_Static &L){
    for(int i = 0; i < MAXSIZE; i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

void InitList_Dynamic(SqList_Dynamic &L, int MaxSize){
    L.MaxSize = MaxSize;
    L.data = new int [MaxSize];
    L.length = 0;
}

// 增加动态线性表的长度
void IncreaseSize(SqList_Dynamic &L, int len){
    int *p = L.data; //指针指向原数组
    L.data = new int [L.MaxSize + len]; // 顺序表更改存储空间
    for (int i = 0; i < L.length ; i++){
        L.data[i] = p[i]; // 将数据拷贝到新空间
    }
    L.MaxSize += len;
    delete p; // 释放原空间
    return;
}

int main (){
    SqList_Dynamic L;
    int MaxSize = 10;
    InitList_Dynamic(L, MaxSize);
    IncreaseSize(L, 10);

    cout << L.length << endl;

    return 0;
}