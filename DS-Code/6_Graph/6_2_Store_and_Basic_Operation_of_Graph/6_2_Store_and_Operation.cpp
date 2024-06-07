#include<iostream>
using namespace std;

#define MaxVertexNum 100

// 邻接矩阵法
typedef struct{
    char vex[MaxVertexNum]; // 顶点表
    int edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵

    int vexnum, arcnum; // 定点数和边数 
} MGraph;

// 邻接表法

// 边表结点
typedef struct ArcNode{
    int adjvex; // 弧指向的顶点
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 顶点表
typedef struct VNode{
    int data; // 顶点信息
    ArcNode *firstarc; // 指向边表的第一个结点的指针
} VNode, AdjList[MaxVertexNum];

// 定义整个邻接表
typedef struct {
    AdjList vertices; 
    int vexnum, arcnum;
} ALGraph;

