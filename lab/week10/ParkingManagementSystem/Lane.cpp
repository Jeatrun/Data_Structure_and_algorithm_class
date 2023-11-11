#include "ParkingLot.h"
#include "Lane.h"
#include <stdio.h>
#include <stdlib.h>

void queueInit(Lane *L)
{
    L = (Lane *)malloc(sizeof(Lane));
    L->front = NULL;
    L->rear = NULL;
}

void enQueue(Lane *L, Car *car)
{
    laneNode *p;
    p = (laneNode *)malloc(sizeof(laneNode));

    // judge whether it's full
    if (queueLength(L) == MAX_LANE)
    {
        printf("Lane is full!\n");
        return;
    }
    else
    {
        // if queue is empty
        if (queueEmpty(L))
        {
            L->front = p;
            L->rear = p;
            p->car = car;
            p->next = NULL;
        }
        else
        {
            L->rear->next = p;
            L->rear = p;
            p->car = car;
            p->next = NULL;
        }
    }
}

Car *deQueue(Lane *L)
{
    if (queueEmpty(L))
    {
        printf("Lane is empty!\n");
        return 0;
    }
    else
    {
        laneNode *p;
        p = L->front;
        L->front = L->front->next;
        return p->car;
    }
}

int queueLength(Lane *L)
{
    if (!queueEmpty(L))
    {
        laneNode *p;
        p = L->front;
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
        return 0;
    }
}

bool queueEmpty(Lane *L)
{
    return (L->front == NULL);
}
