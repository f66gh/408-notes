#include<iostream>
using namespace std;

// 注意写法，*LNode更侧重节点，LinkList更侧重链表
typedef struct LNode{
    int data;
    LNode *next;
} LNode, *LinkList;

// 不带头节点的链表
void InitListNoHead (LinkList &L){
    L->next = NULL;
}

// 带头结点的链表
void InitList (LinkList &L){
    L = new LNode;
    L->next = NULL;
}

int main(){
    // 测试初始链表
    LinkList L;
    InitList(L);
    LNode *p = L;
    for (int i = 0; i < 5; i++){
        p->next = new LNode;
        p = p->next;
        p->data = i;
        p->next = NULL;
    }
    p = L->next;
    while(p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    return 0;
}