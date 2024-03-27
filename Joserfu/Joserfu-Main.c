
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


//��ʼ������
int InitList(LinkList *L){
    //�����ڴ�
    *L=(LinkList)malloc(sizeof(Node));
    //�ڴ����ʧ��
    if(*L==NULL){
        printf("�ڴ�����ʧ��\n");
    }
        //�ڴ����ɹ�
    else{
        (*L)->next=*L;
    }
}

int CreateFromTail(LinkList L,int *geshu){
    //����һ���µ�����������β�ڵ㿪ʼ��������
    Node *r,*s;
    //����һ��ͷ�ڵ�ָ���һ��β�ڵ�ָ��
    int flag=1;
    //����һ����־λ�������ж��Ƿ��������
    r=L;
    //��ͷ�ڵ�ָ�븳ֵ��β�ڵ�ָ��
    int c;
    //����һ����������ΪElemtype�ı���c
    int i=1;
    while(flag){
        printf("���������룺");
        scanf("%d",&c);
        //�Ӽ�����������
        if(c>0){
            s=(Node*)malloc(sizeof(Node));
            //Ϊβ�ڵ�����ڴ�
            s->data.secrect=c;
            s->data.number=i;
            r->next=s;
            //��β�ڵ��nextָ��ָ���·�����ڴ�
            r=s;
            //��β�ڵ�ָ��ָ���·�����ڴ�
            *geshu=i;
        }
        else{
            flag=0;
            r->next=L->next;
            //��β�ڵ��nextָ��ָ��ͷ�ڵ����һ���ڵ�
        }
        i++;
    }
    printf("\n");
    return(0);
}

int DelLL(LinkList L,int e,int *a){
    if(e<1){
        printf("����Ƿ�\n");
        return(0);
    }

    int i,j=1;
    LinkList r,s,z;
    r=L->next;
    z=L->next;
    for(i=0;i<e;i++){
        if(e==1){
            while(j>0){
                z=z->next;
                if(z->next==L->next||z==NULL){
                    j--;
                }
            }
            z->next=L->next->next;
            s=L->next;
            L->next=L->next->next;
            *a=r->data.secrect;
            if(L!=L->next){
                free(s);
            }
            else{
                printf("����Ϊ��\n");
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
            printf("ɾ��λ�ò�����\n");
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
        printf("����Ϊ��\n");
        return(0);
    }
    while(j>0){
        printf("��ţ�%d ���룺%d\n",r->data.number,r->data.secrect);
        r=r->next;
        if(r==L->next||r==NULL){
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
        if(r==L->next ||r==NULL){
            j--;
        }
    }
    printf("���ݲ�����\n");
    return(0);
}


int main() {
    int geshu;
    LinkList L;
    InitList(&L);
    CreateFromTail(L,&geshu);
    printf("��ʼ����Ϊ��%d\n",geshu);

    bianli(L);

    printf("������ֹ��m:");

    int m,i,*liebiao,delnum=0,location,j,a;
    liebiao=(int*)malloc(sizeof(int)*geshu);
    LinkList r,s;
    r=L->next;
    scanf("%d",&m);
    if(m<2){
        printf("����Ƿ�,Ĭ��mΪ3\n");
        m=3;
    }
    while(geshu>0){
        if(geshu==1){
            liebiao[delnum]=r->data.number;
            delnum++;
            geshu--;
        }
        else{
            for(i=2;i<=m;i++){
                r=r->next;
            }
            printf("rdn=%d\n",r->data.number);
            location=Find(L,r->data.number);
            liebiao[delnum]=r->data.number;
            delnum++;
            geshu--;
            r=r->next;
            DelLL(L,location,&m);

        }

    }
    printf("���Ϊ��\n");
    bianli(L);
    for(i=0;i<delnum;i++){
        printf("��%d�����е�Ϊ��%d  \n",i+1,liebiao[i]);
    }
    printf("\n");





    return 0;
}