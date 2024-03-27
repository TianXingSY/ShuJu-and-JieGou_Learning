//
// Created by l1460 on 2024/3/27.
//
#include "LinkList.h"
#include <stdio.h>

int main(){
    LinkList L,r,s;
    Elemtype min;
    int i=0;
    InitList(&L);
    CreateFromTailWithoutInput(L);
    bianli(L);
    r=L->next;
    min=r->data;
    while(r!=NULL){
        if(r->data<min){
            min=r->data;
            s=r;
        }
        r=r->next;
        i++;
    }
    r=s->next;
    s->data=r->data;


}