#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    DNode *prior, *next;
} DNode, *LinkList;

void InitList(LinkList &L){
    L = new DNode;
    L->prior = NULL;
    L->next = NULL;
}

// 在P节点后插入s节点
void InsertNextDNode(DNode *p, DNode *s){
    s->next = p->next;
    p->next = s;
    s->prior = p;
    // 注意考虑s的下一个节点是NULL的情况
    if(s->next != NULL) 
        s->next->prior =s;
}

// 删除p节点的后续节点
void DeleteNextDNode(DNode *p){
    if (p->next == NULL) return;
    // 这段写得是真抽象
    if (p->next->next == NULL){
        delete p->next;
        p->next = NULL;
    }else{
        p->next = p->next->next;
        delete p->next->prior;
        p->next->prior = p;
    }
}

int main(){
    LinkList L ;
    InitList(L);
    DNode *s = new DNode;
    s->data = 1;
    DNode *r = new DNode;
    r->data = 2;
    InsertNextDNode(L,s);
    InsertNextDNode(L,r);
    DeleteNextDNode(L);

    DNode *p = L->next;
    while(p != NULL) {
        cout << p->data <<endl;
        p = p->next;
    }
    return 0;
}