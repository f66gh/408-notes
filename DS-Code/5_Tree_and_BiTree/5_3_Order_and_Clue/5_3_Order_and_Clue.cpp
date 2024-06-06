#include<iostream>
#define MaxSize 100
using namespace std;

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

bool DeQueue(SqQueue &Q, int &x){
    if(QueueEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; // 注意这里是+1
    return true;
}

/**
 * @brief 
 * 二叉树的链式定义
 */
typedef struct BiTNode{
    int data;
    BiTNode  *lchild, *rchlid;
}BiTNode, *BiTree;

void visit(BiTNode *T){
    cout << T->data <<endl;
}

// 先序遍历，NLR
void PreOrder(BiTree T){
    if(T == NULL) return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchlid);
}

// 中序遍历，LNR
void InOrder(BiTree T){
    if(T == NULL) return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchlid);
}

// 后续遍历，LRN
void PostOrder(BiTree T){
    if(T == NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchlid);
    visit(T);
}

/**
 * @brief 
 * 二叉树的层次遍历，重点记忆
 *  1. 首先将二叉树的根节点入队
 *  2. 若队列非空，则队头结点出队，访问该节点，若它有左孩子，则将左孩子入队，若它有右孩子，则将其右孩子入队
 *  3. 重复第2步，直到队列为空
 */
void LevelOrder(BiTree T){
    // 初始化队列和出队列结点
    SqQueue Q;
    InitQueue(Q);
    BiTNode *p;
    
    // 入栈
    EnQueue(Q, T);

    while(!QueueEmpty(Q)){
        DeQueue(Q, p);
        visit(T);
        if(T->lchild != NULL){
            EnQueue(Q, T->lchild);
        }
        if(T->rchlid != NULL){
            EnQueue(Q, T->rchlid);
        }
    }
}

/**
 * @brief 
 * 规定：若无左子树，令lchlid指向其前驱结点；若无右子树，令rchlid指向其后继结点。增加两个ltag标志位
 * tag为0表示结点的孩子，1表示前驱后继
 */
typedef struct ThreadNode{
    int data;
    ThreadNode  *lchild, *rchlid;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

/**
 * 二叉树的线索化
 * 将二叉链表中的空指针改成指向前驱或者后继的线索，而前驱或者后继的信息只有在遍历时才能得到，故线索化的实质是遍历一次二叉树。
 * 以中序线索二叉树的建立为例。设指针pre指向刚刚访问过的节点，指针p指向正在访问的结点，即pre指向p的前驱。
 * 在中序遍历的过程中，检查P的左指针是否为空，若为空就将它指向pre；检查pre的右指针是否为空，若为空了就将它指向p、
 * 我这里按照PPT上的代码，王道书我不太理解
*/
void InTread(ThreadTree &p){
    if(p == NULL) return;
    InTread(p->lchild);
    visitThread(p);
    InTread(p->rchlid);
}

// 先序线索化，多加了一个判断条件看自己的左指针是否已经指向了前驱结点，否则会在两个结点中锁死
void PreThread(ThreadTree &p){
    if(p == NULL) return;
    visitThread(p);
    if(p->ltag == 0){
        PreThread(p->lchild);
    }
    PreThread(p->rchlid);
}

// 全局变量
ThreadNode *pre = NULL;

// 在visit函数中写
void visitThread(ThreadTree p){
    if(p->lchild == NULL){
        p->lchild = pre;
        p->ltag = 1;
    }
    if(pre != NULL && pre->rchlid == NULL){
        pre->rchlid = p;
        p->rtag = 1;
    }
    pre = p;
}

// 中序线索化二叉树T
void CreateInThread(ThreadTree p){
    pre = NULL;
    if (p == NULL) return;
    InTread(p);
    // 当访问到最后一个结点时，pre 和 p都指向这个结点。令此结点rtag等于1
    if(pre->rchlid == NULL){
        pre->rtag = 1;
    }
}

// 中序线索二叉树的后继，当没有右孩子时指针指向的是后继；当有右孩子时找的是右孩子这棵树最左边的节点。
ThreadNode *ThreadHead(ThreadNode *p){
    if(p->rtag == 1) return p->rchlid;
    p = p->rchlid;
    while(p->ltag == 0) p = p->lchild;
    return p;
}

// 中序线索二叉树的前驱，当没有左孩子时指向的是前驱；当有左孩子时找的是左孩子这颗树最右边的节点
ThreadNode *ThreadNext(ThreadNode *p){
    if(p->ltag == 1) return p->lchild;
    p = p->lchild;
    while(p->rtag == 0) p = p->rchlid;
    return p;
}

int main(){

    BiTree T = new BiTNode;

    return 0;
}