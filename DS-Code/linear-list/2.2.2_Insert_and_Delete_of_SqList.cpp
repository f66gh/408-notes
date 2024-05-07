#include<iostream>
#define MaxSize 10
using namespace std;

typedef struct{
    int data[MaxSize];
    int length = 0;
} SqList;

void InitSqList(SqList &L){
    for (int i = 0; i < MaxSize; i++){
        L.data[i] = 0;
    }
    return ;
}

// 在第i个位置上插入某一个元素
bool ListInsert(int i, int e, SqList &L){
    // 判断 i是否有效
    if (i < 1 || i > L.length + 1) return false;
    // 判断顺序表是否已满
    if (L.length >= MaxSize) return false;
    // 将第i个及其后面的元素后移，从最后的元素开始挪
    // 我在这踩坑了，注意循环次数，以免少挪一位
    for (int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除，删除表中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(int i, int &e, SqList &L){
    if (i < 1 || i > L.length + 1) return false;
    if (L.length <= 0) return false;
    e = L.data[i - 1];
    for (int j = i; j <= L.length - 1; j++){
        L.data[j - 1] = L.data[j];
    }
    L.data[L.length - 1] = 0;
    L.length--;
    return true;
}

int main (){
    SqList L;
    int e;
    InitSqList(L);
    ListInsert(1, 1, L);
    ListInsert(2, 2, L);
    ListInsert(3, 3, L);
    ListInsert(3, 4, L);
    ListDelete(3, e, L);
    for(int i = 0 ; i< L.length; i++){
        cout<< L.data[i]<<endl;
    }
    cout<< e <<endl;
    return 0;
}

