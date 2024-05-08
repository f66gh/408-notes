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

//按位查找，返回第i个节点
LNode * GetElem(LinkList L, int i){
    // 省略判断i是否合法
    LNode *p = L;
    for (int j = 0; j < i; j++){
        p = p->next;
    }
    return p;
}

//按值查找，返回节点
LNode * LocateElement(LinkList L, int e){
    // 省略判断是否合法
    LNode *p = L;
    while(p != NULL){
        p = p->next;
        if(p->data == e){
            return p;
        }
    }
    return NULL;
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

    LNode *q = GetElem(L, 3);

    cout << q->data <<endl;

    LNode *s = LocateElement(L, 3);

    cout << s->data << endl;

    p = L->next;
    while(p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    return 0;
}