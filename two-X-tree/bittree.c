//
// Created by l1460 on 24-4-18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;
}bittree;
//������ǰ����
bittree *createtree(bittree *root) {
    char c;
    c=getchar();
    if (c == '#') {
        return NULL;
    }
    else{
        root = (bittree *) malloc(sizeof(bittree));
        printf("������ֵ��");
        root->data=c;
        root->left=createtree(root->left);
        root->right=createtree(root->right);
        return root;
    }
}

int PreOrder(bittree *root) {
    if (root == NULL) {
        return 0;
    }
    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return 0;
}