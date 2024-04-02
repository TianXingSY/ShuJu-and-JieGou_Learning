//
// Created by l1460 on 2024/4/2.
//
#include "SeqStack.c"
//利用顺序栈实现十进制转换二进制


int Ten_To_0o(int num) {
    SqStack S;
    InitStack(&S);
    while (num) {
        Push(&S, num % 2);
        num /= 2;
    }
    while (S.top!=-1) {
        Pop(&S, &num);
        printf("%d", num);
    }
    return 0;
}

int main() {
    int num;
    printf("请输入一个十进制数：");
    scanf("%d", &num);
    Ten_To_0o(num);
    return 0;
}