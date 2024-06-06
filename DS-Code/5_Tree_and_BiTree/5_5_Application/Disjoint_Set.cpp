#include<iostream>
#define SIZE 100
using namespace std;

/*
    并查集的下标表示元素名，若元素不是根节点则下标存储父节点的下标（元素名），若元素是根节点，存储这棵树的所有结点的和的相反数
*/

int UFSets[SIZE]; // 集合元素数组（双亲指针数组）

// 并查集的初始化操作
void Initial(int S[]){
    for(int i = 0; i < SIZE; i++){
        S[i] = -1;
    }
}

// 在并查集S中查找并返回包含元素x的树的根，时间复杂度为O(d)，d为树的深度
int Find(int S[], int x){
    while(S[x] >= 0) x = S[x];
    return x;
}

// 求两个不相交子集合的并集，时间复杂度为O(1)
void Union(int S[], int Root1, int Root2){
    if(Root1 == Root2) return ; // 如果两棵树是相同的则直接返回
    S[Root1] += S[Root2]; // 将Root2子集元素个数加到Root1子集
    S[Root2] = Root1; // 将Root2连到Root1下面
}


/**
 * @brief 
 * 合并优化
 * n个元素构成的集合树的深度为n，则Find操作的最坏时间复杂度为O(n)。
 * 在合并时让小树合并到大树上，find就不费事了。
 * 采用这种方法构造的树高度不小于 (log2n)向下取整+1
 */
void AdvancedUnion(int S[], int Root1, int Root2){
    // 先判断那棵树元素少
    if(S[Root1] <= S[Root2]){
        // 因为是负数，故若Root2比1小
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }else{
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

/**
 * @brief 
 * 当所查元素x不在树的第二层时，在算法中增加一个压缩路径的功能，将从根到元素x路径上的所有元素变成根的孩子
 * @param S 
 * @param x 
 * @return int 
 */
int AdvancedFind(int S[], int x){
    int root = x;
    // 循环找到根
    while(S[root] >= 0) root = S[root];

    // 循环将元素的父节点
    while(x != root){
        int t = S[x]; // t循环指向x的父节点
        S[x] = root; // 将x挂到节点下
        x = t; // 让x等于之前的父节点
    }
    return root;
}

int main(){

    return 0;
}