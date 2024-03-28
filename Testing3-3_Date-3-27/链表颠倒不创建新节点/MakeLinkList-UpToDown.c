//
// Created by l1460 on 2024/3/28.
//
#include "LinkList.c"

int main() {
    LinkList L,r,s,z;
    InitList(&L);
    CreateFromTailWithoutInput(L);
    bianli(L);
    r=L->next;
    s=L->next;
    while(r->next){
        r=r->next;
    }
    z=r;
    while(L->next!=z){

    }
    bianli(L);
}