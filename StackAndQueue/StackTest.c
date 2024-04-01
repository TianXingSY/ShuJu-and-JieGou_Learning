//
// Created by l1460 on 2024/4/1.
//
#include "StackList.c"
//利用函数检测字符数组里括号数量是否匹配
int checkBrackets(char *str) {
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        i++;
    }
    return count;
}
//利用函数检测字符数组里括号数量是否匹配,使用栈
int checkBrackets2(char *str) {
    int i = 0,c;
    int count = 0;
    LinkStack Stack;
    InitStack(&Stack);
    while (str[i] != '\0') {
        if (str[i] == '(') {
            Push(Stack, str[i]);
        }
        else if (str[i] == ')') {
            if (StackEmpty(Stack) == 1) {
                return -1;
            } else {
                Pop(Stack,&c);
            }
        }
        i++;
    }
    return StackLength(Stack);
}