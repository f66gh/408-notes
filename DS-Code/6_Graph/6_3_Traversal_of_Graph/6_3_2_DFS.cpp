#include<iostream>
using namespace std;
#define MAX 100

bool visited[MAX];

void DFSTraverse(Graph G){
    for(int i = 0 ; i < MAX; i++){
        visited[i] = false;
    }
    for(int i = 0; i < MAX; i++){
        if(!visited[i]){
            DFS(G, i);
        }
    }
}

void DFS(Graph G, int i){
    visit[i];
    visited[i] = true;
    for(w = FirstNeighbor(G, i); w >=0; w = NextNeighbor(G, i, w)){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}