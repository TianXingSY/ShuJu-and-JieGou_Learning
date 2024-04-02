//
// Created by l1460 on 2024/4/1.
//
#include "StackList.c"
#include "string.h"
//利用函数检测字符数组里括号数量是否匹配
char *str= "{3+[4*(4+5)]}}";


int main() {
    LinkStack S;
    InitStack(&S);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S)) {
                return 0;
            }
            char c;
            Pop(S, &c);
            if ((c == '(' && str[i] != ')') || (c == '[' && str[i] != ']') || (c == '{' && str[i] != '}')) {
                return 0;
            }
        }
    }
    if (StackEmpty(S)) {
        return 1;
    }
    return 0;
}