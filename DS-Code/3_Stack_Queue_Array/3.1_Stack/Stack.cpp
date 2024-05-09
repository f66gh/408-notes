#include<iostream>
#define MaxSize 10
using namespace std;

// 顺序栈，设一个指针指示当前栈顶元素
/*
    下列代码的top指的是栈顶元素而不是栈顶上面的空间。
    设初始top = -1，栈满 top = MaxSize - 1
    栈空 top = -1, 栈长 len = top + 1 
*/
typedef struct{
    int data[MaxSize];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack &S){
    S.top = -1;
}

// 栈空
bool StackEmpty(SqStack S){
    if(S.top == -1) return true;
    return false;
}

// 栈满
bool StackFull(SqStack S){
    if(S.top == MaxSize - 1) return true;
    return false;
}

// 进栈
bool Push(SqStack &S, int x){
    if(S.top >= MaxSize - 1) return false;
    S.top++;
    S.data[S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, int &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    S.top --;
    return true;
}

// 读栈顶元素
bool GetTop(SqStack &S, int &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

// 链栈
typedef struct LinkNode{
    int data;
    LinkNode * next;
} LiStack;

int main(){
    // 没啥技术难度就没写测试代码
    return 0;
}