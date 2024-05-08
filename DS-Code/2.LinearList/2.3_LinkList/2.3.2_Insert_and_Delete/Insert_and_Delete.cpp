#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    LNode* next;
} LNode, *LinkList;

void InitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

void InitListNoHead(LinkList &L){
    L = new LNode;
    L = NULL;
}

// 求长度(头结点不算)
int ListLength(LinkList &L){
    int len = 0;
    LNode* p = L->next;
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// 在第i个位置插入e数据
bool ListInsert(LinkList &L, int i ,int e){
    int len = ListLength(L);
    if(i < 1 || i > len + 1) return false;
    LNode *p = L;
    // 找到第i个位置的上一个节点
    for(int j = 0; j < i - 1; j++){
        p = p->next;
    }
    LNode *q = p->next;
    p->next = new LNode;
    p->next->data = e;
    p->next->next = q;
    return true;
}

// 指定节点的前插
void InsertPriorNode(LNode* p, int e){
    // 遍历做不到，直接将此节点的副本查到自己的后面然后改变自己的数据
    LNode *q = p->next;
    p->next = new LNode;
    p->next->data = p->data;
    p->next->next = q;
    p->data = e;
}

// 删除第i个位置的节点并返回删除的数据
bool ListDelete(LinkList &L, int i, int &e){
    int len = ListLength(L);
    if(i < 1 || i > len + 1) return false;
    LNode *p = L;
    // 找到第i个位置的上一个节点
    for(int j = 0; j < i - 1; j++){
        p = p->next;
    }
    LNode *q = p->next->next;
    e = p->next->data;
    delete p->next;
    p->next = q;
    return true;
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

    InsertPriorNode(p, 11110);

    ListInsert(L, 3, 11);
    ListInsert(L, 7, 111);
    ListInsert(L, 9, 1111);
    
    int e = 0;
    ListDelete(L, 7, e);
    cout << e << endl;

    p = L->next;
    while(p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    return 0;
}