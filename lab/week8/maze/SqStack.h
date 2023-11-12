/*SqStack.h*/
#include <malloc.h>
#define MAXSIZE 100
typedef int SElemType;

typedef struct {
    SElemType x;
    SElemType y;

}data;

typedef struct
{
    data mazecor[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *&S)
{
    S = (SqStack *)malloc(sizeof(SqStack));
    S->top = -1;
}

void DistroyStack(SqStack *&S)
{
    free(S);
}

bool StackEmpty(SqStack *S)
{
    return (S->top == -1);
}

bool Push(SqStack *&S, int x,int y)
{
    if (S->top == MAXSIZE - 1)
    {
        printf("Stack is full!");
        return false;
    }
    else
    {
        S->top++;
        S->mazecor[S->top].x =x ;
        S->mazecor[S->top].y =y;
        return true;
    }
}

bool Pop(SqStack *&S, int &x,int &y)
{
    if (StackEmpty(S))
    {
        printf("Stack is empty!");
        return false;
    }
    else
    {
        S->mazecor[S->top].x =x ;
        S->mazecor[S->top].y =y;

        S->top--;
        return true;
    }
}

bool GetTop(SqStack *S, int &x,int &y)
{
    if (StackEmpty(S))
    {
        printf("Stack is empty!");
        return false;
    }
    else
    {
        x=S->mazecor[S->top].x ;
        y=S->mazecor[S->top].y;

        return true;
    }
}

int StackLentgh(SqStack *S)
{
    if (S->top == -1)
    {
        printf("stack is empty!");
        return 0;
    }
    else
    {
        return S->top + 1;
    }
}

void DisplayStack(SqStack *S)
{
    /*
        Existed error:
            if (StackEmpty)
        fixed:
            if (StackEmpty(S))
    */
    if (StackEmpty(S))
    {
        printf("Stack is empty!");
        return;
    }
    int i;
    for (i = S->top; i >= 0; i--)
    {
        printf("[%d,%d]", S->mazecor[i].x, S->mazecor[i].y);
    }
}
