#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100

//definition
typedef int ElemType ;
typedef struct Node{
    ElemType data;
    Node *lchild,*rchild;
} btNode;



void createBT(btNode *&b,char *str)
{
    btNode *St[MAX_TREE_SIZE],*p=NULL;
    int top=-1,i=0,k=0;
    char ch;
    b=NULL;
    ch=str[i];
    while(ch!='\0'){
        switch (ch) {
            //'(':push to st,set k to 1
            case '(':
                top++;
                St[top]=p;
                k=1;
            break;
            
            case ',':k=2;
            break;
            
            //pop the stack
            case ')': top--;
            break;

            default:
                p=(btNode *)malloc(sizeof(btNode));
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL){
                    b=p;
                }
                else{
                    switch (k) 
                    {
                        case 1:
                            St[top]=p->lchild;
                            break;
                        case 2:
                            St[top]=p->rchild;
                            break;
                    }
                }

        }
        i++;
        ch=str[i];       


    }
}

void DispBT(btNode *b){
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL || b->rchild!=NULL){
            printf("(");
            DispBT(b->lchild);
            printf(",");
            DispBT(b->rchild);
            printf(")");
        }
    }
}