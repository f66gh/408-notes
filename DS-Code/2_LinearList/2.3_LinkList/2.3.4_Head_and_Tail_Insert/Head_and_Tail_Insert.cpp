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

// 头插法
void List_HeadInsert(LinkList &L, int e){
    LNode *p = L->next;
    L->next = new LNode;
    L->next->data = e;
    L->next->next = p;
}

// 尾插法，其实前面三节用的测试链表就是尾插法，这里只是单独元素的尾插，循环尾插见这些代码的main函数
void List_TailInsert(LinkList &L, int e){
    // 先遍历到尾巴
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = new LNode;
    p->next->data = e;
    p->next->next = NULL;
}

int main(){
    // 测试初始链表
    LinkList L;
    InitList(L);
    LNode *p = L;
    List_HeadInsert(L, 100);
    List_TailInsert(L, 200);
    for (int i = 0; i < 5; i++){
        p->next = new LNode;
        p = p->next;
        p->data = i;
        p->next = NULL;
    }
    List_HeadInsert(L, 101);
    List_TailInsert(L, 201);
    p = L->next;
    while(p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    return 0;
}