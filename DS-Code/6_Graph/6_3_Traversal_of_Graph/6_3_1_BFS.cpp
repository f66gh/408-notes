#include<iostream>
#define MAX_VERTEX_NUM 100
#define INFINITE 10000 // 定义正无穷
using namespace std;


// 伪代码
bool visited[MAX_VERTEX_NUM]; // 访问标记数组

void BFSTraverse(Graph G){ // 对图G进行广度优先遍历
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false; // 访问标记数组初始化
    }

    InitQueue(Q); // 定义辅助队列

// 如果标记数组对应元素没有被遍历，则遍历，这里用for循环是防止多个联通子图的出现，BFS自己只能遍历一个联通子图。
    for(int i = 0 ; i < G.vexnum; i++){ 
        if(!visited[i]){
            BFS(G, i);
        }
    }
}

// 用邻接表实现广度优先搜索，当这个点遍历完之后才入队。
void BFS(ALGraph G, int i){
    visit(i);
    visited[i] = true;

    EnQueue(Q, i);
    while(!IsEmpty(Q)){
        DeQueue(Q, v);

        // 先把每一层都遍历完再遍历下一层的
        for(p = G.vertices[v].firstarc; p; p = p->nextarc){
            // 监测v的所有邻接点
            w = p->adjvex;
            if(visited[w] == false){
                visit[w];
                visited[w] = true;
                EnQueue(Q, w); // 让v的邻接点入队
            }
        }
    }
}

// 采用邻接矩阵法实现广度优先遍历
void BFS(MGraph G, int i){
    visit(i);
    visited[i] = true;

    EnQueue(Q, i);

    while(!IsEmpty(Q)){
        DeQueue(Q, v);
        // 邻接表是用指针表示的边，而矩阵是用的数组，初始化方式不一样
        for(w = 0; w < G.vexnum; w++){
            if(visited[w] == false && G.edge[v][w] == 1){
                visit(w);
                visited[w] = true;
                Enqueue(Q, w);
            }
        }
    }
}

/*
    BFS中，邻接矩阵和邻接表的邻居判断方法可以简化统一为使用FirstNeighbor(G, u)和NextNeighbor(G, u, w)

    FirstNeighbor(G, u)表示u结点的第一个邻接结点, -1为没有
    NextNeighbor(G, u, w)表示u结点在w结点后的邻接结点，-1为w已经是最后一个结点
    使用这两个函数可以将上述两个函数整合简化为一个
*/ 
void BFS(Graph G, int i){
    visit[i];
    visited[i] = true;
    EnQueue(Q, i);
    while(!IsEmpty(Q)){
        DeQueue(Q, v);
        for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
            if(!visited[w]){
                visit[w];
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

// BFS算法求解单源最短路径问题，利用BFS由近及远遍历的性质
void BFS_MIN_Distance (Graph G, int u){
    // d[i]表示u到i的最短路径
    for(int i = 0; i < MAX_VERTEX_NUM; i++)
        d[i] = INFINITE;
    visit[u];
    visited[u] = true;
    d[u] = 0; // 结点到自己的最短路径长度为0
    EnQueue(Q, u);
    while(!IsEmpty(Q)){
        DeQueue(Q, u);
        // 这里的u是下一层的u
        for(w = FirstNeighbor(G, u); w <= 0; w = NextNeighbor(G, u, w)){
            visit[i];
            visited[i] = true;
            d[w] = d[u] + 1;
            EnQueue(Q, w);
        }
    }
}