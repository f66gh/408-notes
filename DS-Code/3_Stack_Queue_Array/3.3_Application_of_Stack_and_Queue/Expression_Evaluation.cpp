#include<iostream>
#include<string>
using namespace std;
#define MaxSize 100

// fw 这都得用chatgpt

typedef struct{
    char data [MaxSize];
    int top = -1;
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
bool Push(SqStack &S, char x){
    if(S.top >= MaxSize - 1) return false;
    S.top++;
    S.data[S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, char &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    S.top --;
    return true;
}

// 读栈顶元素
bool GetTop(SqStack &S, char &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

// 中缀转后缀
string ExpressionEvaluation(SqStack &S, string str){
    int len = str.length();
    string outcome;

    for (int i = 0; i < len; i++){

        // 遇到操作数直接加入后缀表达式
        if(isalpha(str[i])) outcome += str[i];

        // 遇到界限符，左括号直接入栈，右括号将栈内到左括号之前的元素弹出加入到后缀表达式
        else if (str[i] == '(') Push(S, str[i]);
        else if (str[i] == ')') {
            char top;
            Pop(S, top);
            while(top != '('){
                outcome += top;
                Pop(S, top);
            }
        }

        // 遇到运算符
        else if (str[i] == '*' || str[i] == '/') {
            char topElem;
            // 如果栈不空且栈顶元素的优先级大于当前运算符的优先级，将栈顶元素出栈并加入到后缀表达式中
            while (!StackEmpty(S) && (GetTop(S, topElem) && (topElem == '*' || topElem == '/'))) {
                outcome += topElem;
                Pop(S, topElem);
            }
            // 当前运算符入栈
            Push(S, str[i]);
        }
        
        // 对于加减运算符，其优先级最低，在遇到加减运算符时，将栈中所有运算符出栈并加入到后缀表达式中
        else if (str[i] == '+' || str[i] == '-') {
            char topElem;
            while (!StackEmpty(S) && (GetTop(S, topElem) && (topElem == '+' || topElem == '-' || topElem == '*' || topElem == '/'))) {
                outcome += topElem;
                Pop(S, topElem);
            }
            // 当前运算符入栈
            Push(S, str[i]);
        }
    }
    
    // 将栈中剩余的运算符依次弹出并加入到后缀表达式中
    while (!StackEmpty(S)) {
        char topElem;
        Pop(S, topElem);
        outcome += topElem;
    }

    return outcome;
}

int main(){
    SqStack S;
    InitStack(S);
    string postfix = ExpressionEvaluation(S, "A+B*(C-D)-E/F");
    cout << postfix << endl;
    return 0;
}
