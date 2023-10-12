#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
// definition
typedef int ElemType;
typedef struct LNode
{

    ElemType data;

    struct LNode *next;
} LinkNode;

// create
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    /*
    错误代码:
    LinkNode *s, *r;
    r = L;
    L = (LinkNode *)malloc(sizeof(LinkNode));

    错误总结:在L分配新空间前先把L赋值给r,导致给L分配空间后r所指向的内存空间已不是链表,以至于最后的数值无法传给链表
    */

    LinkNode *s, *r; // s : new node r:final(current)node
    // 1.create a empty list
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;          // let the pointer point at head node
    L->next = NULL; // initialize the next pointer of head node to null

    // 2.create a new node ,take every elem at a[i] into the data , insert the node at the end of the list
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = NULL;
        r->next = s;
        r = r->next;
    }
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%4d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// delete
void DeleteList(LinkNode *&L)
{
    LinkNode *p = L;
    while (p != NULL)
    {
        free(L);
        L = p->next;
        free(p);
        p = L;
    }
}
//length
int ListLength(LinkNode *L)
{
    int n=0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}
//get
bool GetElem(LinkNode *L, int i,ElemType &e)
{
    int j = 0;
    LinkNode *p = L;
    while (p != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
        e = p->data;

        return true;
    
}

//find/locate
int LocateElem(LinkNode *L, ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        i++;
        p=p->next;

    }
    if(p==NULL){
        return 0;
    } 
    else {
        return i;
    }

}

//insert
bool ListInsert(LinkNode *&L, int i, ElemType e){   
    LinkNode *p=L;   
    int j=0;
    
    //find the jth element
    while(p!=NULL&&j<i-1){
        j++;
        p=p->next;
    }
    
    if(p==NULL){
        return false;
    }
    //insert the new node
    else{
        LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));//new node to insert
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
    
    
}