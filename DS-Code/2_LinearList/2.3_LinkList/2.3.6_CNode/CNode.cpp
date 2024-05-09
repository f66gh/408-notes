#include<iostream>
using namespace std;

// 注意循环链表的头节点也算在循环内！
// 循环单链表
typedef struct CNode{
    int data;
    CNode *next;
} CNode, *LinkList;

void InitList (LinkList &L){
    L = new CNode;
    L->next = L;
}

// 循环双链表
typedef struct CDNode{
    int data;
    CDNode *next, *prior;
} CDNode, *LinkListDouble;

void InitListDouble(LinkListDouble &L){
    L = new CDNode;
    L->next = L;
    L->prior = L;
}

// 判断链表是否为空
bool Empty(LinkList &L){
    if(L->next == L) return true;
    return false;
}

// 判断节点P是否为链表的头节点
bool isTail(LinkList L, CNode *p){
    if(p->next == L) return true;
    return false;
}

int main(){

    return 0;
}