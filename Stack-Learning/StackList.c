//
// Created by l1460 on 2024/3/27.
//
typedef int Elemtype;

typedef struct stack {
    Elemtype data;
    struct stack *next;
}Stack,*LinkStack;