#include <malloc.h>
#include <stdio.h>

typedef char* ElemType;
typedef struct qnode

{
    ElemType data;
    qnode *next;

} LinkQNode;

typedef struct
{
    LinkQNode *front;
    LinkQNode *rear;

} LinkQueue;

void InitLinkQueue(LinkQueue *&q)
{
    q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = q->rear = NULL;
}

void DestroyLinkQueue(LinkQueue *&q)
{
    LinkQNode *p1, *p2;
    if (q == NULL)
    {
        printf("the queue doesn't exist!");
        return;
    }
    p1 = q->front;
    while (p1 != NULL)
    {
        p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    free(p1);
    free(q);
}

bool QueueEmpty(LinkQueue *q)
{
    return (q->front == NULL);
}

void EnQueue(LinkQueue *&q, ElemType e)
{
    LinkQNode *p;
    p = (LinkQNode *)malloc(sizeof(LinkQNode));

    /*
    exited problem:
        p->data = e;
        p->next = NULL;
    reason:
        deliver a same pointer 'e' so that every data was pointed at a same space when changing 'e'
    */

    p->data = (ElemType)malloc(100);
    
    //copy e to data
    int i = 0;
    while (e[i] != '\0')
    {
        p->data[i] = e[i];
        i++;
    }
    p->data[i] = '\0';

    p->next = NULL;
    if (q->front == NULL)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}
bool DeQueue(LinkQueue *&q, ElemType &e)
{
    LinkQNode *p;
    if (!QueueEmpty(q))
    {
        p = q->front;
        e = p->data;
        q->front = p->next;
        free(p);
        return true;
    }
    else
        return false;
}

void DisplayQueue(LinkQueue *q)
{

    if (!QueueEmpty(q))
    {
        LinkQNode *p;
        p = q->front;
        while (p != NULL)
        {
            printf("%4s", p->data);
            p = p->next;
        }
    }
    else
    {
        printf("Queue is empty!");
    }
}

int LengthQueue(LinkQueue *q)
{
    if (!QueueEmpty(q))
    {
        LinkQNode *p;
        p = q->front;
        int count = 0;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }
        return count;
    }
    else
    {
        printf("Queue is empty!");
        return 0;
    }
}