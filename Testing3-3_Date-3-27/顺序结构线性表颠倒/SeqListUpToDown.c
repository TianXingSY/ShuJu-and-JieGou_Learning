//
// Created by l1460 on 2024/3/27.
//
#define SIZE 10
#include "xxb.c"
#include "StackList.c"


int main(){
    SeqList L;
    LinkStack P;
    InitStack(&P);
    L.last=-1;
    int i,inp;
    for(i = 0;i < SIZE;i++){
        printf("请输入第%d个元素：",i+1);
        scanf("%d",&inp);
        L.data[++L.last] = inp;
    }
    Elemtype e;
    while (L.last > -1){
        DelList(&L,1,&e);
        Push(P,e);
    }
    while (!StackEmpty(P)){
        Pop(P,&e);
        L.data[++L.last] = e;
    }
    for(i = 0;i < L.last+1;i++){
        printf("%d ",L.data[i]);
    }
}