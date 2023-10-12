/*SqStack.h*/
#include <malloc.h>
#define MAXSIZE 100
typedef struct{
    int data[MAXSIZE];
    int top;
}SqStack;
void InitStack(SqStack* &S){
    S=(SqStack*)malloc(sizeof(SqStack));
    S->top=-1;
}

void DistroyStack(SqStack* &S){
    free(S);
}

bool StackEmpty(SqStack* S){
    return (S->top==-1);
}

bool Push(SqStack* &S,int e){
    if(S->top==MAXSIZE-1){
        printf("Stack is full!");
        return false;
    }
    else{
        S->top++;
        S->data[S->top]=e;
        return true;
    }
}

bool Pop(SqStack* &S,int &e){
    if(S->top==-1){
        printf("Stack is empty!");
        return false;
    }
    else{
        e=S->data[S->top];
        S->top--;
        return true;
    }

}

bool GetTop(SqStack* S,int &e){
    if(S->top==-1){
        printf("Stack is empty!");
        return false;
    }
    else{
        e=S->data[S->top];
        return true;
    }
}

int StackLentgh(SqStack*S){
    if(S->top==-1){
        printf("stack is empty!");
        return 0;
    }else{
        return S->top+1;
    }
}

