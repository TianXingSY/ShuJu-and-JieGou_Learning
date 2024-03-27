//
// Created by l1460 on 2024/3/27.
//

#include "xxb.c"


int main(){
    SeqList L;
    L.last=-1;
    int i,j=0,temple[10] = {1,2,3,4,5,6,7,8,9,10};
    for(i = 0;i < 10;i++){
        L.data[++j] = temple[i];
    }

}