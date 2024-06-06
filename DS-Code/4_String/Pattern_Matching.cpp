#include<iostream>
using namespace std;

// 从位置i开始，长度为m的子串
void SubString(string &sub, string S, int i, int m){
    for(int j = i; j < m + i; j ++){
        sub += S[j];
    }
    return;
}

// 子串和模式串匹配
bool StrCompare(string sub, string T){
    // if(sub == T) return true;
    // else return false;
    int len = T.length();
    for(int i = 0; i < len; i++){
        if(sub[i] != T[i]) 
            return false;
    }
    return true;
}

// 朴素模式匹配算法：将主串中所有长度为m的子串依次与模式串对比，直到找到一个完全匹配的子串，或所有的子串都不匹配为止
// 最多匹配n-m+1个子串，最坏时间复杂度O(nm)
int Index(string S, string T){
    int lenS = S.length();
    int lenT = T.length();
    string sub;
    for(int i = 0; i < lenS - lenT + 1; i++){
        SubString(sub, S, i, lenT);
        if(StrCompare(sub, T)) 
            return i;
        sub = ""; // 别忘了清空子串
    }
    return -1;
}

int StrCompareKMP(string sub, string T, int i){
    int len = T.length();
    for(; i < len; i++){
        if(sub[i] != T[i])
            return i;
    }
    return len;
}

// KMP算法：主串指针不回溯，模式串指针不一定回溯至头。注意这里的数组编号从1开始
//时间复杂度O(n + m)
int Index_KMP(string S, string T, int next[]){
    int i = 1, j = 1;
    while(i <= S.length() && j <= S.length()){
        if(j == 0 || S[i] == T[i]) {
            i++;
            j++;
        }
        else j = next[j];
    }
    if(j > T.length()) return i - T.length(); // 匹配成功
    else return 0;
}


// 求next和nextval数组
void get_next(string T, int next[], int nextval[]){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length()){
        if(j == 0 || T[i] == T[j]){
            i++;
            j++;
            next[i] = j; // 若Pi = Pj，则next[j+1] = next[j] + 1
        }
        else j = next[j];
    }

    nextval[1] = 0;
    for(int p = 2; p <= T.length(); p++){
        if(T[next[p]] == T[p]) nextval[p] = nextval[next[j]];
        else nextval[j] = next[j];
    }
}


int main(){

    string s = "ababcabcacbab";
    string t = "abcac";
    // int next = [0,1,1];  
    int i = Index(s, t);
    cout << i <<endl;
    return 0;
}