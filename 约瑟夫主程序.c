
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10
typedef struct joserfu{
    int number;
    int secrect;
}Elemtype;


typedef struct node{
    Elemtype data;
    struct node *next;
}Node,*LinkList;


//初始化链表
int InitList(LinkList *L){
    //申请内存
    *L=(LinkList)malloc(sizeof(Node));
    //内存分配失败
    if(*L==NULL){
        printf("内存申请失败\n");
    }
        //内存分配成功
    else{
        (*L)->next=*L;
    }
}

int CreateFromTail(LinkList L,int *geshu){
    //创建一个新的链表，并从尾节点开始输入数据
    Node *r,*s;
    //定义一个头节点指针和一个尾节点指针
    int flag=1;
    //定义一个标志位，用于判断是否继续输入
    r=L;
    //将头节点指针赋值给尾节点指针
    int c;
    //定义一个数据类型为Elemtype的变量c
    int i=1;
    while(flag){
        printf("请输入密码：");
        scanf("%d",&c);
        //从键盘输入数据
        if(c>0){
            s=(Node*)malloc(sizeof(Node));
            //为尾节点分配内存
            s->data.secrect=c;
            s->data.number=i;
            r->next=s;
            //将尾节点的next指针指向新分配的内存
            r=s;
            //将尾节点指针指向新分配的内存
            *geshu=i;
        }
        else{
            flag=0;
            r->next=L->next;
            //将尾节点的next指针指向头节点的下一个节点
        }
        i++;
    }
    printf("\n");
    return(0);
}

int DelLL(LinkList L,int e,int *a){
    if(e<1){
        printf("输入非法\n");
        return(0);
    }

    int i;
    LinkList r,s;
    r=L->next;
    for(i=0;i<e;i++){
        if(e==1){
            s=L->next;
            L->next=L->next->next;
            if(L!=L->next){
                free(s);
            }

            return(1);
        }
        if(i==e-2){
            s=r;
        }
        else if(i==e-1){
            s->next=r->next;
            *a=r->data.secrect;
            free(r);
            return(1);
        }
        if(r->next==L->next){
            printf("删除位置不存在\n");
            return(0);
        }
        r=r->next;
    }
    return(0);
}

int InsertLL(LinkList L,int e,Elemtype a){
    // e：要插入的位置；a：要插入的值
    if(e<1){
        printf("输入非法\n");
        return(0);
    }

    int i;
    LinkList r=L->next,s,In;
    // r：用来遍历链表，s：存储要插入位置的前一个节点，In：用来创建新节点
    In=(Node*)malloc(sizeof(Node));
    In->data=a;
    for(i=0;i<e;i++){
        if(e==1){
            // 特殊情况，e等于1时，直接将新节点插在头节点之前
            In->next=L->next;
            L->next=In;
            return(1);
        }
        if(i==e-2){
            // 保存要插入位置的前一个节点
            s=r;
        }
        else if(i==e-1){
            // 将新节点插入到指定位置
            s->next=In;
            In->next=r;
            return(1);
        }
        if(r==L){
            // 插入位置不存在
            printf("插入位置不存在\n");
            return(0);
        }
        else if(r->next==L->next && i==e-2){
            // 特殊情况，插入位置为链表尾，直接将新节点插在链表尾
            r->next=In;
            In->next=L->next;
            return(0);
        }
        r=r->next;
    }
    return(0);
}

int bianli(LinkList L){
    LinkList r;
    r=L->next;
    int j=1;
    if(L==L->next){
        printf("链表为空\n");
        return(0);
    }
    while(j>0){
        printf("编号：%d 密码：%d\n",r->data.number,r->data.secrect);
        r=r->next;
        if(r==L->next){
            j--;
        }
    }
    printf("\n");
    return(1);
}

int Find(LinkList L,int x){
    LinkList r;
    int i=0,j=1;
    r=L->next;
    while(j){
        if(r->data.number==x){
            return(i+1);
        }
        r=r->next;
        i++;
        if(r==L->next){
            j--;
        }
    }
    printf("数据不存在\n");
    return(0);
}


int main() {
    int geshu;
    LinkList L;
    InitList(&L);
    CreateFromTail(L,&geshu);
    printf("初始人数为：%d\n",geshu);

    bianli(L);

    printf("输入终止数m");

    int m,i,*liebiao,delnum=0,location,a;
    liebiao=(int*)malloc(sizeof(int)*geshu);
    LinkList r,s;
    r=L->next;
    scanf("%d",&m);
    if(m<2){
        printf("输入非法,默认m为3\n");
        m=3;
    }
    while(geshu>0){

        if(geshu==1){
            liebiao[delnum+1]=r->data.number;
            delnum++;
            geshu--;
        }
        else{
            for(i=1;i<m;i++){
                r=r->next;
            }
            location=Find(L,r->next->data.number);
            liebiao[delnum+1]=r->next->data.number;
            delnum++;
            geshu--;
            DelLL(L,location,&m);
        }

    }
    bianli(L);
    for(i=0;i<delnum;i++){
        printf("第%d个出列的是为：%d  \n",i+1,liebiao[i]);
    }
    printf("\n");

    /*int dd;
    int cnu;
    printf("输入想删除的节点:");
    scanf("%d",&dd);
    DelLL(L,dd,&cnu);
    geshu--;

    bianli(L);

    Elemtype cahru;
    printf("输入想插入的节点位置和编号和密码:");
    scanf("%d%d%d",&dd,&cahru.number,&cahru.secrect);
    InsertLL(L,dd,cahru);
    geshu++;

    bianli(L);


    int nn;
    printf("输入想删除的节点的值:");
    scanf("%d",&cnu);
    dd = Find(L,cnu);
    DelLL(L,dd,&nn);
    geshu--;
    bianli(L);*/



    return 0;
}
