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
}