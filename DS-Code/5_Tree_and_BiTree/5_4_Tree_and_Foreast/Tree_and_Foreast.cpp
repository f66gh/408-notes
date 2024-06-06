#include<iostream>
#define MaxSize 100
using namespace std;

// 树的双亲表示法，可以很快找到双亲，但找孩子需要遍历整个树。

// 树的结点定义
typedef struct{
    int data;
    int parent;
} PTNode;

// 树的类型定义，包含所有结点
typedef struct{
    PTNode nodes[MaxSize];
    int n; // 树结点总数
} PTree;

// 孩子表示法（略），寻找孩子操作很方便，但寻找双亲的操作需要遍历n个结点中孩子链表指针域所指向的n个孩子列表。

// 孩子兄弟表示法：又称为二叉树表示法。以二叉链表作为树的存储结构。第一个指针是第一个孩子，第二个指针指向自己的兄弟
// 将树或森林转化为二叉树也是这么转的
typedef struct CSNode{
    int data;
    CSNode *fchild, *nextBrother;
} CSNode;



int main(){

    return 0;
}