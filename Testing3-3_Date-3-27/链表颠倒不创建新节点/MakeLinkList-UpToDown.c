//
// Created by l1460 on 2024/3/28.
//
#include "LinkList.c"

int main() {
    LinkList L,r,s,z;
    InitList(&L);
    CreateFromTail(L);
    bianli(L);
    r=L->next;
    z=r->next;
    s=z;
    r->next=NULL;
    while(z){
        L->next=s;
        z=z->next;
        s->next=r;
        r=s;
        s=z;
    }
    bianli(L);
}