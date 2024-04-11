//
// Created by l1460 on 24-4-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// 定义顺序栈结构
typedef struct {
    int data[MAX_SIZE];
    int top;
} SeqStack;

// 初始化栈
void initStack(SeqStack *stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(SeqStack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(SeqStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈
void push(SeqStack *stack, int item) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// 出栈
int pop(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// 获取栈顶元素
int peek(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// 模拟游戏过程
void simulateGame(int N, int m, int n) {
    SeqStack stack;
    initStack(&stack);

    // 初始化参与游戏的人员编号
    for (int i = N; i >= 1; --i) {
        push(&stack, i);
    }

    srand((unsigned int)time(NULL)); // 随机种子

    int start = rand() % N + 1; // 随机生成开始报数的序号
    int count = 1; // 计数器
    int eliminated = 0; // 记录已经出圈的人数

    printf("开始游戏！\n");
    while (eliminated < n) {
        int person = pop(&stack); // 出栈

        // 如果是开始报数的人或者已经报到了m，则出圈
        if (count == m || person == start) {
            printf("第%d个出圈的人是：%d\n", eliminated + 1, person);
            eliminated++;
            count = 1; // 重置计数器
        } else {
            push(&stack, person); // 入栈
            count++;
        }
    }
}

int main() {
    int N, m, n;

    printf("请输入总人数 N: ");
    scanf("%d", &N);

    printf("请输入报数的数字 m: ");
    scanf("%d", &m);

    printf("请输入要出圈的人数 n (n <= N): ");
    scanf("%d", &n);

    simulateGame(N, m, n);

    return 0;
}