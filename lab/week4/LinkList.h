#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
//definition
typedef int ElemType ;
typedef struct LNode{

    ElemType data;

    struct LNode *next;
} LinkNode;

//create
void CreateListR(LinkNode *&L,ElemType a[],int n){
    LinkNode *s,*r;
    r=L;
    //1.create a empty list
    L = (LinkNode *)malloc(sizeof(LinkNode));
    //2.take every elem in a[i], create a new node ,insert at the end of the list
    for(int i=0;i<n;i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = NULL;
        r->next = s;
    }
    //3.set the next pointer of the last node to null

    r->next = NULL;
}

void DispList(LinkNode *L){
    LinkNode *p = L->next;
    while(p!=NULL){
        printf("%4d ",p->data);
        p = p->next;
        }
}