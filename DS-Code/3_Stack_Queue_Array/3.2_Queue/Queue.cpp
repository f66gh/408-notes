#include<iostream>
#define MaxSize 10
using namespace std;

// 这里有队头指针front和队为指针rear，队尾内的元素是空的
/*
    直接过渡到循环队列
    初始操作：Q.front = Q.rear = 0;
    进队操作：队不满时先送值至队尾元素再将队尾指针加1
    出队操作：队不空时先取队头元素值，再将队头指针加1

    这里使用牺牲一个单元区分队空or队满，约定以队头指针在队尾指针的下一个位置作为队满的标志
*/
typedef struct{
    int data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool QueueEmpty (SqQueue Q){
    if(Q.front == Q.rear) return true;
    return false;
}

bool QueueFull (SqQueue Q){
    if((Q.front + 1) % MaxSize == Q.rear) return true;
    return false;
}

bool EnQueue(SqQueue &Q, int x){
    if(QueueFull(Q)) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int x){
    if(QueueEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; // 注意这里是+1
    return true;
}
/*
    链式队列，本质是同时有头指针和尾指针的单链表。头指针指向头节点，尾指针指向尾节点
    注意这里的rear是最后一个节点，有值；带头结点front的下一个节点有值，和顺序队列不一样
*/
typedef struct LinkNode{
    int data;
    LinkNode *next;
} LinkNode;
typedef struct{
    LinkNode *front, *rear;
} *LinkQueue;

// 这里使用的是带头节点的链式存储
void InitLinkQueue(LinkQueue &Q){
    Q->front = new LinkNode;
    Q->rear = Q->front;
    Q->rear->next = NULL;
}

// 链表队列没有栈满的问题
void EnLinkQueue(LinkQueue &Q, int x){
    LinkNode *p = new LinkNode;
    p->data = x;
    Q->rear->next = p;
    Q->rear = p;
    Q->rear->next = NULL;
}

// 出队
bool DeLinkQueue(LinkQueue &Q, int& x){
    if(Q->front == Q->rear) return false;
    LinkNode *p = new LinkNode;
    p = Q->front->next;
    x = p->data;
    Q->front->next = p->next;
    // 当删到最后一位时，注意别丢了rear
    if(Q->rear == p) Q->rear = Q->front;
    delete p;
    return true;
}

int main(){
    // 逻辑难度不大，不做测试
    return 0;
}